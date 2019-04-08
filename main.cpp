// main.cpp 
// Josh Middleton
// 4/1/2019
/*	
	Make a menu that lets users create accounts
	also lets users mkae deposits, withdrawls and transfers
	added bonus, users can add two accounts together
	users can also estimate future balance based on rate and span in years.
	users can also view all acounts created.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Account.h"

using namespace std;

void transfer(Account& fromAccount, Account& toAccount, double);
void transfer(Account& fromAccount, Account& toAccount);
double calculateFutureValue(double, float, int);

int main() {
	
	Account one, two, three;		// initialize default constructed objects
	string tempName;				// string for name
	vector<Account> bankVector;		// initialize vector of class Account
	
	int choice;					// initialize needed variables
	int years;
	int index;
	char ans;
	float rate;
	double withdraw;
	double deposit;
	double amount;
	double trans_amt;

	do {		// use a do loop to constantly cycle through the menu until sentinel value is input.
	cout << "Menu Options:" << "\n1 - Create New Account" << "\n2 - Withdraw Money" << "\n3 - Deposit Money" << "\n4 - Transfer Money"
		<< "\n5 - Sum Two Accounts" << "\n6 - Calculate Future Balance" << "\n7 - View All Accounts" << "\n8 - Exit" << endl;
	cin >> choice;
	switch (choice) {
	case 1:			// create a new account.
		cout << "Enter the account name: ";			
		cin >> tempName;
		one.setName(tempName);					// sets the account name
		cout << "Enter the account balance: $";
		cin >> amount;
		one.setBalance(amount);			// sets the account balance
		one.setOverdraftState(amount);	// sets the overdraft state
		bankVector.push_back(one);		// puts the account inside the vector
		cout << endl;
		break;
	case 2:			// withdraw
		cout << "Enter the account index to withdrawal from: ";				// asks wich account they want to withdrawal from
		cout << "\nEnter a number up to: " << bankVector.size();			// show how large the index is.
		cout << '\n';
		cin >> index;
		cout << '\n' << bankVector[index - 1];
		one = bankVector[index - 1];
		cout << "\nEnter withdrawal amount: $";
		cin >> withdraw;
		one.withdraw(withdraw);
		cout <<'\n' << one << endl;
		cout << endl;
		break;
	case 3:			// deposit
		cout << "Enter the account index to deposit to: ";
		cout << "\nEnter a number up to: " << bankVector.size();
		cout << '\n';
		cin >> index;
		cout << '\n' << bankVector[index - 1];
		one = bankVector[index - 1];
		cout << "\nEnter deposit amount: $";			// enter amount to deposit.
		cin >> deposit;
		one.deposit(deposit);
		cout << '\n' << one << endl;
		cout << endl;
		break;
	case 4:			// transfer
		cout << "Enter the account index you wish to transfer FROM: " << endl;			// asks wich account they want to transfer from 
		cout << "\nEnter a number up to: " << bankVector.size();			// show how large the index is.
		cout << '\n';
		cin >> index;
		cout << '\n' << bankVector[index - 1];				// selsects the proper index 1 = 0
		one = bankVector[index - 1];						// assigns the first object to the selected vector element.
		cout << endl;
		
		cout << "\nEnter the account index you wish to transfer TO: " << endl;			// specifies second account.
		cout << "\nEnter a number up to: " << bankVector.size();			// show how large the index is.
		cout << '\n';
		cin >> index;
		cout << '\n' << bankVector[index - 1];
		two = bankVector[index - 1];						// initialize second object with selected index.
		
		
		cout << "\nwould you like to transfer the whole balance? <y/n>" << endl;			// asks to transfer whole balance.
		cin >> ans;
		if (ans == 'n') {
			cout << "\nHow much would you like to transfer?" << endl;			// specifies transfer amount.
			cout << '$';
			cin >> trans_amt;
			transfer(one, two, trans_amt);			// calls transfer function for custom amount.
		}
		else {
			transfer(one, two);						// calls transfer function for the whole account balance.
		}
		two.setOverdraftState(two.getBalance());	// set overdraft state on the second account.

		cout << '\n' << one << endl;				// output the updated objects.
		cout << '\n' << two << endl;
		cout << endl;
		break;
	case 5:			// add two accounts
		cout << "Enter the account index you wish to add: " << endl;
		cout << "\nEnter a number up to: " << bankVector.size();			// show how large the index is.
		cout << '\n';
		cin >> index;
		cout << '\n' << bankVector[index - 1];
		one = bankVector[index - 1];				// assign object to selected index.

		cout << "\nEnter the index of the account to add to: " << endl;
		cout << "\nEnter a number up to: " << bankVector.size();
		cout << '\n';
		cin >> index;
		cout << '\n' << bankVector[index - 1];
		two = bankVector[index - 1];				// assign object to selected index.

		three = one + two;			// add object together.
		cout << "\nThe new account balance is: $" << three.getBalance();		// cout output the newly made objects balance.
		cout << endl;
		break;
	case 6:			// estimate future value
		cout << "Enter the index of the account to estimate future value:" << endl;
		cout << "\nEnter a number up to: " << bankVector.size();			// show how large the index is.
		cout << '\n';
		cin >> index;
		cout << '\n' << bankVector[index - 1];
		one = bankVector[index - 1];				// assign object to selected index.
		cout << endl;

		cout << "Interest rate: ";			// collect interest rate
		cin >> rate;
		cout << endl;
		
		cout << "How many years? " << endl;			// collect the span in years
		cin >> years;			
		cout << endl;

		one.setBalance(calculateFutureValue(amount, rate, years));			// call recursive function
		cout << "Future Balance of " << one.getName();
		cout << " in" << years <<" years: $" << one.getBalance();
		cout << endl;
		break;
	case 7:			// print all accounts
		for (unsigned i = 0; i < bankVector.size(); i++) {

		cout << (bankVector[i]) << '\n';				// should print all the objects in the vector.
		cout << endl;
		}
		break;
	}
	} while (choice != 8);

	cout << "EXIT SYSTEM" << endl;				// once sentinel value is input 

	system("pause");
	return 0;
}

void transfer(Account& fromAccount, Account& toAccount, double transferAmount) {

	fromAccount.withdraw(transferAmount);		// fromAccount.withdraw() with desired transfer amount as parameter
	toAccount.deposit(transferAmount);			// toAccount.deposit() with the desired transfer amount as parameter
}

void transfer(Account& fromAccount, Account& toAccount) {		
	
	toAccount.deposit(fromAccount.getBalance());			// use the balance of the fromAccount to deposit in toAccount
	fromAccount.withdraw(fromAccount.getBalance());			// withdraw the balance fromAccount.
}

double calculateFutureValue(double amount, float rate, int years) {
	//that takes in an initial balance, a yearly interest rate, and number of years as parameters 
	//and recursively computes the ending balance given the number of years input

	if (years == 0) {		// base case.
		return amount;
	}
	else {
		return amount + (rate)*calculateFutureValue(amount, rate, years - 1);		// recursive case.
	}
};

