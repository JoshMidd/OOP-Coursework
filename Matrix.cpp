// Matrix.cpp
// Josh Middleton
// 3/28/2019
// Implementation of needed Overloaded operators and member functions of class Matrix in 'Matrix.h"

#include <iostream>
#include "Matrix.h"

// Init function to fill matrices with zeroes by default
void Matrix::init() {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			data[i][j] = 0;					// set each element to 0.
		}
	}

}

// Overload + operator to add two Matrix objects.
Matrix Matrix::operator+(const Matrix& m) {
	Matrix out;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			out.data[i][j] = data[i][j] + m.data[i][j];		// loop through each element and add each element.
		}
	}

	return out;
}

// Overload - operator to subtract two Matrix objects.
Matrix Matrix::operator-(const Matrix& m) {
	Matrix out;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			out.data[i][j] = data[i][j] - m.data[i][j];		// loop through each matrix and subtract each element.
		}
	}

	return out;
}

// Overload * operator to multiply two Matrix objects.
Matrix Matrix::operator*(const Matrix& m) {
	Matrix out;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			out.data[i][j] = data[i][j] * m.data[i][j];		// loop through each matrix and multiply each element. 
		}
	}

	return out;
}

// Overload == operator to check equivalence.
bool Matrix::operator==(const Matrix& m) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (data[i][j] != m.data[i][j]) {		// if the matrices are not equal return false
				return false;
			}
		}
	}
	return true;
}

// Overloaded =! operator to check inequality
bool Matrix::operator!=(const Matrix& m) {	
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (data[i][j] != m.data[i][j]) {		// if the matrices are not equal return true
				return true;
			}
		}
	}
	return false;
}

// Overloaded ++ operator (prefix Increment)
Matrix Matrix::operator++() {
	Matrix out;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			out.data[i][j] = data[i][j] + 1;		// loope through each element and add 1
		}
	}

	return out;
}

// overloaded -- operator (prefix decrement)
Matrix Matrix::operator--() {
	Matrix out;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			out.data[i][j] = data[i][j] - 1;		// loop through each element and subtract 1
		}
	}

	return out;
}

// Overloaded ostream operator <<. 
ostream& operator<<(ostream& os, const Matrix& m) {

	os << "This is what's in the matrix:" << endl;
	for (int i = 0; i < Matrix::SIZE; ++i) {
		for (int j = 0; j < Matrix::SIZE; ++j) {
			os << m.data[i][j] << " ";
		}
		os << endl;
	}

	return os;

}

// overloaded istream operator >>.
istream& operator >> (istream& in, Matrix& m)
{
	for (int i = 0; i < Matrix::SIZE; ++i) {
		in >> m.data[i][0] >> m.data[i][1] >> m.data[i][2] >> m.data[i][3];		// loop through each row anf each element in it
	}
	return in;
}