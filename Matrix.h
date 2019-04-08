// Matrix.h 
// Josh Middleton
// 3/28/19
// Declare a class Matrix and create all data members of the class including overloaded operators. 

#include <iostream>
#include <array>
using namespace std;

class Matrix {
private:
	static const int SIZE = 4;		// constant size of rows and columns
	int data[SIZE][SIZE];
	void init();			// pivate function to initialize the matrix to 0

public:
	Matrix() { init(); };						// Constructor with init function call to set matrix to zero
	Matrix operator+(const Matrix& m);			// Overloaded + function prototype
	Matrix operator-(const Matrix& m);			// Overloaded - function prototype
	Matrix operator*(const Matrix& m);			// Overloaded * function prototype
	bool operator==(const Matrix& m);			// Overloaded == function prototype
	bool operator!=(const Matrix& m);			// Overloaded != function prototype
	Matrix operator++();						// Overloaded ++ Prefix function prototype
	Matrix operator--();						// Overloaded -- Prefix function prototype


	friend ostream& operator <<(ostream& os, const  Matrix& m);		// Overloaded output stream << function prototype
	friend istream& operator >>(istream& in, Matrix& m);			// Overloaded input stream >> function prototype
};