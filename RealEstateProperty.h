// Josh Middleton
// 3/1/2019
// RealEstateProperty.h
/*	create a class with member functions set/get.
	all member function prototypes.
	a constructor which has no values
	an overloaded constructor which initializes its values.
	all private variables.
*/


#include <iostream>
#include <string>			// allows program to use C++ string data type.
using namespace std;

class RealEstateProperty {
public:
	// constructor with no parameters
	RealEstateProperty() {
		name = " ";
		price = 0;
		cost = 0;
		rooms = 0;
		bathrooms = 0;
		sqrFt = 0;

	}
	// constructor with multiple parameters
	RealEstateProperty(string propertyName, unsigned int homeSalePrice, unsigned int homeOwnerMonthlyCost, unsigned int bedrooms, unsigned int restrooms, unsigned int squareFeet) {
		name = propertyName;
		price = homeSalePrice;
		cost = homeOwnerMonthlyCost;
		rooms = bedrooms;
		bathrooms = restrooms;
		sqrFt = squareFeet;

	}


	void RealEstateProperty::setName(string);				// set name function prototype.
	const string& RealEstateProperty::getName();			// get name function prototype.

	void RealEstateProperty::setPrice(unsigned int homeSalePrice);			// set price function prototype.
	unsigned int RealEstateProperty::getPrice() const;			// get price function prototype.

	void RealEstateProperty::setCost(unsigned int homeOwnerMonthlyCost);			// set cost function prototype. 
	unsigned int RealEstateProperty::getCost() const;			// set cost function prototype. 

	void RealEstateProperty::setRooms(unsigned int bedrooms);			// set rooms function prototype.
	unsigned int RealEstateProperty::getRooms() const;			// get rooms function prototype.

	void RealEstateProperty::setBathrooms(unsigned int restrooms);			// set bathrooms function prototype.
	unsigned int RealEstateProperty::getBathrooms() const;			// set bathrooms function prototype.

	void RealEstateProperty::setSqrFt(unsigned int squareFeet);			// set square feet function prototype.
	unsigned int RealEstateProperty::getSqrFt() const;			// get square feet function protorype.


	string toString();						// overloaded string function to print all values.
	double RealEstateProperty::calculateMortgage(float interest, double payment);			// calculate mortgage function prototype.
	int RealEstateProperty::calculateMortgage(float interest, int payment, int term);			// overloaded calculate mortgage prototype.
	double RealEstateProperty::calculateTotalMonthlyCost(float interest, int payment, int term);			// calculate total monthly cost function prototype. 

private:

	string name;				// data member containing the property name.
	unsigned int price{ 0 };		// data member containing property value
	unsigned int cost{ 0 };			// data member containing HOA monthly cost.
	unsigned int rooms{ 0 };			// data member containing amount of rooms.
	unsigned int bathrooms{ 0 };		// data member containing amount of bathrooms.
	unsigned int sqrFt{ 0 };			// data member containing square footage of house.

};

