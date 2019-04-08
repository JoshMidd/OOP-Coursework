//Include header

#include <iostream> 
#include <random>
#include <ctime>
#include <iomanip> 
using namespace std;

const int RACE_END = 70;

// prototypes
void moveTortoise(int* const);
void moveHare(int* const);
void printCurrentPositions(const int* const, const int* const);

default_random_engine engine{static_cast<unsigned int>(time(0))};
uniform_int_distribution<int> randomInt{1, 10};

int main() {
	int tortoise{ 1 };
	int hare{ 1 };
	int timer{ 0 };


   int* const tortoisePtr(&tortoise);
   int* const harePtr(&hare);
	
   cout << "ON YOUR MARK, GET SET\nBANG               !!!!"
      << "\nAND THEY'RE OFF    !!!!\n";


   // loop through the events
   while (tortoise != RACE_END && hare != RACE_END) {
	   moveTortoise(&tortoise);		// move tortoise
	   moveHare(&hare);		// move hare
	   printCurrentPositions(&tortoise, &hare);		// print current position
	   ++timer;			// increment timer
   } 

   if (tortoise >= hare) {
      cout << "\nTORTOISE WINS!!! YAY!!!\n";
   }
   else {
      cout << "Hare wins. Yuch.\n";
   }

   cout << "TIME ELAPSED = " << timer << " seconds" << endl;
  

   system("pause");
   return 0;
}  

void moveTortoise(int* const tPtr) {

	switch (randomInt(engine)) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5: 
		*tPtr + 3;			// "fast plod" 3 squares to the right.
		break;
	case 6:
	case 7:
		*tPtr - 6;		// "slip" 6 squares to the left.
		if (*tPtr <= 0) {
			*tPtr = 1;
		}	
		break;
	case 8:
	case 9:
	case 10:
		*tPtr + 1;		// "slow plod"	1 square to the right.
		break;
	}
}

void moveHare(int* const hPtr) {
	
	switch (randomInt(engine)) {
	case 1:
	case 2:
		break;
	case 3:
	case 4:
		*hPtr + 9;		// "big hop" 9 squares to the right.
		break;
	case 5:
		*hPtr - 12;		// "big slip" 12 squares to the left.
		if (*hPtr <= 0) {
			*hPtr = 1;
		}
		break;
	case 6:
	case 7:
	case 8:
		*hPtr + 1;		// "small hop" 1 square to the right.
		break;
	case 9:
	case 10:
		*hPtr - 2;		// "small slip" 2 squares to the left.
		if (*hPtr <= 0) {
			*hPtr = 1;
		}
		break;

}

void printCurrentPositions(const int* const tPtr, const int* const hPtr) {

	cout << "The Tortoise's position: " << *tPtr;
	cout << "\nThe Hare's position: " << *hPtr;

	if (*tPtr == *hPtr) {
		//cout << "\nOUCH!!!" << endl;
	}
}