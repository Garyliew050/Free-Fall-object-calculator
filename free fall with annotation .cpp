#include <iostream>
#include <math.h>
#include <iomanip>
#include <cctype>
#include <stdio.h>
#include <iostream>
#include <string>


void displayMenu();
void PrintDivider(int length);
void makelist(double Vi, double Vf, double t, double td);
double downDirection();
double upDirection();
double input1();
double input2();
double input3();
//declare all the function we have

using namespace std;
const double g = -9.81;//Since the acceleration of gravity never changes, we declare it constant

int main() {
	int item = 0;// this just an item that we can know the user want to use which function
	bool start = true;
	//this is a bool variable that we can end the program ,the while loop work rely on this bool, if it's false, the loop end, then the program end.
	while (start) {   
		displayMenu();//function call, use this function
		cout << "Enter your choice :";
		cin >> item;//get the value of item
		system("cls");//clear the output
		while (cin.fail()) { //doing a while loop when we have a fail input
			cin.clear();
			cin.ignore(256, '\n');//this two line is to clear the storage of cin function,so that the fail input won't chashed ourprogram
			system("cls");
			PrintDivider(100);   //function call
			cout << "invalid action" << endl;
			displayMenu();
			cout << "Enter your choice :";
			cin >> item;
		}
		cin.clear();
		cin.ignore(256, '\n');//this two line is to clear the storage of cin function,so that the fail input won't chashed ourprogram or running fail
		switch (item) {   // base on the value of item, we have four choice
		case 1: PrintDivider(100);
			downDirection();
			break;
		case 2: PrintDivider(100);
			upDirection();
			break;
		case 3: start = false;//give the star variable false to end the while loop and program.
			PrintDivider(100);
			cout << "\t\tExitted. Have a nice day!" << endl;
			PrintDivider(100);
			break;
		default:
			system("cls");
			PrintDivider(100);
			cout << "Invalid action" << endl;
			break;
		}
	}
}


double input1() {
	double a;//declare a double variable
	cout << "Please enter the initial velocity (ms^-1):";
	cin >> a;//get the initial velocity as the value of variable
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		system("cls");
		PrintDivider(100);
		cout << "Invalid action" << endl;
		PrintDivider(100);
		cout << "Please enter the initial velocity (ms^-1):";
		cin >> a;
	}
	cin.clear();
	cin.ignore(256, '\n');

	return a;
}

double input2() {
	double a;//declare a double variable
	cout << "Please enter the distance from the initial position to the ground (m):";
	cin >> a;//get the distance from the initial position to the ground as the value of variable
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		system("cls");
		PrintDivider(100);
		cout << "Invalid action" << endl;
		PrintDivider(100);
		cout << "Please enter the distance from the initial position to the ground (m):";
		cin >> a;
	}
	cin.clear();
	cin.ignore(256, '\n');
	return a;
}

double input3() {
	double a;//declare a double variable
	cout << "Please enter the time interval to be displayed (s):";
	cin >> a;//get the time interval as the value of variable
	while (cin.fail()||a ==0) { 
		//because the time interval can't be 0 and it will be the divisor in follow code, so we add extra position that we need user rewrite.
		cin.clear();
		cin.ignore(256, '\n');
		system("cls");
		PrintDivider(100);
		cout << "Invalid action" << endl;
		PrintDivider(100);
		cout << "Please enter the time interval to be displayed (s):";
		cin >> a;
	}
	cin.clear();
	cin.ignore(256, '\n');
	return a;
}

//void makelist(double Vi, double Vf, double t, double td) {
//	bool item = true;
//	int count = 0;
//	double distance[10000] = { 0 };
//	double v[10000] = { 0 };
//	cout << setw(8) << "time" << "\t" << setw(12) << "distance" << "\t" << setw(14) << "velocity" << endl;
//	for (double i = 0; i <= t; i = i + td) {
//		distance[count] = Vi * i + (g * i * i) / 2;
//		v[count] = Vi + g * i;
//		cout << fixed << setprecision(2) << setw(8) << i << "\t" << setw(12) << distance[count] << "\t" << setw(14) << v[count] << "\n";
//		if (i != t) {
//			item = false;
//		}
//		else {
//			item = true;
//		}
//		count++;
//	}
//	if (item == false) {
//		cout << fixed << setprecision(2) << setw(8) << t << "\t" << setw(12) << Vi * t + (g * t * t) / 2 << "\t" << setw(14) << Vi + g * t << "\n";
//		// 
//	}
//	cout << "The time of total process is " << t << " seconds, the time interval you chose is " << td << endl;
//}

void makelist(double Vi, double Vf, double t, double td) {
	bool item = true;// this bool variable is to check if the final time can be output in for loop
	int count = 0;   //This int is a tool used to make the array progressive
	int size = t / td + 1;//This int is the size of the array. The value of time divided by the time interval is the number we need to output
	double* distance; // Use pointers to create the array so that we can use the variable as the length of the array 
	distance = new double[size];
	double* v; // Use pointers to create the array so that we can use the variable as the length of the array 
	v = new double[size];
	cout << setw(8) << "time" << "\t" << setw(12) << "distance" << "\t" << setw(14) << "velocity" << endl;
	for (double i = 0; i <= t; i = i + td) {
		*(distance + count) = Vi * i + (g * i * i) / 2;//This is the formula for calculating distance
		*(v + count) = Vi + g * i;//This is the formula for calculating velocity
		cout << fixed << setprecision(2) << setw(8) << i << "\t" << setw(12) << *(distance + count) << "\t" << setw(14) << *(v + count) << "\n";
		if (i != t) {
			item = false;
		}
		else if (i == t) {
			item = true;
		}
		count++;
	}
	if (item == false) {
		cout << fixed << setprecision(2) << setw(8) << t << "\t" << setw(12) << Vi * t + (g * t * t) / 2 << "\t" << setw(14) << Vi + g * t << "\n";
		// if the for loop cann't output the final time,distance and velocity, then we manually output it
	}
	cout << "The time of total process is " << t << " seconds, the time interval you chose is " << td << endl;
}

double downDirection() {
	double Vi, Vf, d, t, td;//declare five double which is initial velocity,final velocity,distance ,total time of movement process and the time interval
	Vi = input1(); //use function to give the value
	Vi = 0 - Vi; //because the direction is down, the velocity must be negative
	d = input2(); //use function to give the value
	Vf = 0 - sqrt(Vi * Vi - 2 * g * d);//because the direction is down, the velocity must be negative
	td = input3();
	t = (Vf - Vi) / g;//This is the formula for calculating time
	t = fabs(t);// because time must be positive ,we use fabs() to make the time positive(whatever it be in past)
	makelist(Vi, Vf, t, td);//function call
	return 0;
}

double upDirection() {
	double Vi, Vf, d, t, D, T, td;//declare five double which is initial velocity,final velocity,distance ,the time of up direction movement process,-
	//- the distance from the highest point to grand, total time and the time interval
	Vi = input1();
	d = input2();
	td = input3();
	t = Vi / g;//when it doing up direction movement process, it will slow down until the speed is 0, so it's the time of up direction movement process.
	t = fabs(t);//because time must be positive ,we use fabs() to make the time positive(whatever it be in past)
	D = d - (g * t * t) / 2;//the distance + the distance of up direction movement process = the distance from the highest point to grand
	T = sqrt(2 * D / -g) + t;//This is the formula for calculating time
	T = fabs(T);
	Vf = Vi + g * T;//This is the formula for calculating final velocity
	makelist(Vi, Vf, T, td);
	return 0;
}

void PrintDivider(int length) {
	for (int i = 0; i < length; i++)
	{
		cout << "-";
	}
	cout << endl;
}


void displayMenu() {
	PrintDivider(100);
	cout << "LIST OF FUNCTIONS \n";
	PrintDivider(100);
	cout << "1. Downward Direction.\n"
		<< "2. Upward Direction.\n"
		<< "3. Exit.\n";
}

