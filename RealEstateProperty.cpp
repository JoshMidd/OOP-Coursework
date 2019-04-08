// realEstateProperty.cpp
// Josh Middleton
// 3/1/2019
/*	all function declarations
*/

#include <iostream>
#include <string>			// allows program to use C++ string data type.
#include <cstdlib>			// allows conversion to and from string.
#include <cmath>			// allows use of exponents.
#include "RealEstateProperty.h"

using namespace std;


// member function that sets the property name.
void RealEstateProperty::setName(string propertyName) {
	name = propertyName;
}

// member function that gets the property name.
const string & RealEstateProperty::getName() {			// pass by reference and keep the name constant.	
	return name;
}

// member function that sets the property sale price. 
void RealEstateProperty::setPrice(unsigned int homeSalePrice) {
	price = homeSalePrice;
}

// member function that gets the property sale price.
unsigned int RealEstateProperty::getPrice() const {
	return price;
}

// member function that sets the HOA monthly cost.
void RealEstateProperty::setCost(unsigned int homeOwnerMonthlyCost) {
	cost = homeOwnerMonthlyCost;
}

// member function that gets the HOA monthly cost.
unsigned int RealEstateProperty::getCost() const {
	return cost;
}

// member function that sets the amount of rooms.
void RealEstateProperty::setRooms(unsigned int bedrooms) {
	rooms = bedrooms;
}

// member function that gets the amount of rooms.
unsigned int RealEstateProperty::getRooms() const {
	return rooms;
}

// member function that sets the amount of bathrooms.
void RealEstateProperty::setBathrooms(unsigned int restrooms) {
	bathrooms = restrooms;
}

// member function that gets the amount of bathrooms. 
unsigned int RealEstateProperty::getBathrooms() const {
	return bathrooms;
}

// member function that sets the amount of square feet.
void RealEstateProperty::setSqrFt(unsigned int squareFeet) {
	sqrFt = squareFeet;
}

// member function that gets the amount of square feet.
unsigned int RealEstateProperty::getSqrFt() const {
	return sqrFt;
}

// function to convert values to string
string RealEstateProperty::toString() {
	string s = "";

	s += "Property name: " + name;
	s += "\nPrice: $" + to_string(price);
	s += "\nHOA Cost: $" + to_string(cost);
	s += "\nBedrooms: " + to_string(rooms);
	s += "\nBathrooms: " + to_string(bathrooms);
	s += "\nSquare Feet: " + to_string(sqrFt);
	s += "\nPrice Per square foot: $" + to_string(price / sqrFt);
	cout << endl;

	return s;
}

// function to calculate monthly payment
double RealEstateProperty::calculateMortgage(float interest, double payment) {

	double monthlyPayment;			// initialize needed variables.
	float loanAmt;
	int numMonths = 360;

	loanAmt = RealEstateProperty::getPrice() - payment;			// get price of the property

	monthlyPayment = ((interest * (pow((1 + interest), numMonths))) / ((pow((1 + interest), numMonths)) - 1)) * loanAmt;			// Calculate monthly payment

	return monthlyPayment;
}

// overloaded function that takes amount of months input to calculate monthly payment
int RealEstateProperty::calculateMortgage(float interest, int payment, int term) {

	int monthlyPayment;			// initialize needed variables.
	int loanAmt;
	int numMonths = term;

	loanAmt = RealEstateProperty::getPrice() - payment;		// get price of the property

	monthlyPayment = ((interest * (pow((1 + interest), numMonths))) / ((pow((1 + interest), numMonths)) - 1)) * loanAmt;			// Calculate monthly payment

	return monthlyPayment;
}

// function that calculates total monthly cost
double RealEstateProperty::calculateTotalMonthlyCost(float interest, int payment, int term) {

	double totalMonthlyCost;

	totalMonthlyCost = RealEstateProperty::calculateMortgage(interest, payment) + RealEstateProperty::getCost();

	return totalMonthlyCost;
}

