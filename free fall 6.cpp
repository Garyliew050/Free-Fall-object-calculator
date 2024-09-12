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


using namespace std;
const double g = -9.81;

int main() {
	int item = 0;
	bool start = true;
	while (start) {
		displayMenu();
		cout << "Enter your choice :";
		cin >> item;
		system("cls");
		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');

			system("cls");
			PrintDivider(100);
			cout << "invalid action" << endl;
			displayMenu();
			cout << "Enter your choice :";
			cin >> item;
		}
		cin.clear();
		cin.ignore(256, '\n');
		switch (item) {
		case 1: PrintDivider(100);
			downDirection();
			break;
		case 2: PrintDivider(100);
			upDirection();
			break;
		case 3: start = false;
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
	double a;
	cout << "Please enter the initial velocity (ms^-1):";
	cin >> a;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "invalid input , please try again!" << endl;
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
	double a;
	cout << "Please enter the distance from the initial position to the ground (m):";
	cin >> a;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "invalid input , please try again!" << endl;
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
	double a;
	cout << "Please enter the time interval to be displayed (s):";
	cin >> a;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "invalid input , please try again!" << endl;
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

void makelist(double Vi, double Vf, double t, double td) {
	bool item = true;
	int count = 0;
	double distance[10000] = { 0 };
	double v[10000] = { 0 };
	cout << setw(8) << "time" << "\t" << setw(12) << "distance" << "\t" << setw(14) << "velocity" << endl;
	for (double i = 0; i <= t; i = i + td) {
		distance[count] = Vi * i + (g * i * i) / 2;
		v[count] = Vi + g * i;
		cout << fixed << setprecision(2) << setw(8) << i << "\t" << setw(12) << distance[count] << "\t" << setw(14) << v[count] << "\n";
		if (i != t) {
			item = false;
		}
		else {
			item = true;
		}
		count++;
	}
	if (item == false) {
		cout << fixed << setprecision(2) << setw(8) << t << "\t" << setw(12) << Vi * t + (g * t * t) / 2 << "\t" << setw(14) << Vi + g * t << "\n";
		// 
	}
	cout << "The time of total process is " << t << " seconds, the time interval you chose is " << td << endl;
}

double downDirection() {
	double Vi, Vf, d, t, td;
	Vi = input1();
	Vi = 0 - Vi;
	d = input2();
	Vf = 0 - sqrt(Vi * Vi - 2 * g * d);
	td = input3();
	t = (Vf - Vi) / g;
	t = fabs(t);
	makelist(Vi, Vf, t, td);
	return 0;
}

double upDirection() {
	double Vi, Vf, d, t, D, T, td;
	Vi = input1();
	d = input2();
	td = input3();
	t = Vi / g;
	t = fabs(t);
	D = d - (g * t * t) / 2;
	T = sqrt(2 * D / -g) + t;
	T = fabs(T);
	Vf = Vi + g * T;
	makelist(Vi, Vf, T, td);
	return 0;
}

void PrintDivider(int length) {
	for (int i = 0; i < length; i++) cout << "-";
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

