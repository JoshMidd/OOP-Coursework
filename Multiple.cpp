// Understanding of Inputs/ Output Operators
// Josh Middleton
// 2/13/19
// Write a program that reads in two integers and determines and prints if the first is a multiple of the second.
// If it is a multiple of the second, the program should print the number of times the first number fits in the second. 
// If it is not a multiple, it should print out “Not a Multiple”.


#include <iostream>										// controls output to screen

using namespace std;

int main() {
	int x{ 0 };											// integer x assigned to 0
	int y{ 0 };											// integer y assigned to 0
	int quotient{ 0 };									// integer quotient assigned to 0

	cout << "Enter an integer \n";						// Prompt user to enter first integer
	cin >> x;											// Assign user input to variable x
	cout << endl;

	cout << "Enter another integer \n";					// Prompt user to enter second integer
	cin >> y;											// Assign user input to variable y
	cout << endl;


	int qoutient = x / y;	

	if (x % y == 0) {
		cout << " " << y << " fits into " << x << " \n" << " " << qoutient << " time's." << endl;
	}

	else {
		cout << "Not a Multiple" << endl;
	}

	system("pause");
	return 0;
}
