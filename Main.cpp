// Main.cpp
// Josh Middleton
// 3/28/19
// Tests Matrix.h and Matrix.cpp


#include <iostream>
#include <array>
#include <iomanip>
#include "Matrix.h"


int main() {

	Matrix one;
	Matrix two;
	Matrix three;

	cout << "Enter a 4x4 matrix : " << endl;					// Gather Matrices from user.
	cin >> one;													// Use overloaded istream to gather input.
	cout << "Enter a 4x4 matrix : " << endl;
	cin >> two;

	cout << "=========================" << endl;

	cout << "The first Matrix you entered :" << endl;			// Use overloaded ostream to output the matrix from the user.
	cout << one;

	cout << "\nThe second Matrix you entered :" << endl;		// Use overloaded ostream to output the matrix from the user.
	cout << two;
	
	cout << "=========================" << endl;
	
	three = one + two;											// Show working overloaded + operator. 
	cout << "matrix addition:" << endl;
	cout << three;												// overloaded ostream outputting matrix addition.

	three = one - two;											// Show working overloaded - operator.
	cout << "\nmatrix subtraction:" << endl;					
	cout << three;												// overloaded ostream outputting matrix subtraction.

	three = one * two;											// Show working overloaded * operator.
	cout << "\nmatrix multiplication:" << endl;
	cout << three;												// overloaded ostream outputting matrix multiplication.

	cout << "\n++matrix:" << endl;								// Show working overloaded operator++ (prefix increment).
	cout << ++three;											// overloaded ostream outputting prefix incrememnt matrix.

	cout << "\n--matrix:" << endl;								// Show working overloaded operator-- (prefix decrement).
	cout << --three;											// overloaded ostream outputting prefix decrement matrix.

	cout << "=========================" << endl;
	
	if (one == two) {											// check to see if matrix one is equivalent to matrix two
		cout << "Matrix 1 is equal to Matrix 2" << endl;		
	}
	else {
		cout << "Matrix 1 is not equal to Matrix 2" << endl;
	}
	system("pause");
	return 0;
}