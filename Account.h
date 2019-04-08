// Account.h
// Josh Middleton
// 4/1/19
/*
	Create a class with name, balance, transaction count, overdraft state, and number of accounts created.
	create a constructor and an overloaded constructor
	prototype all needed class functions.

*/

#include <iostream>
#include <string>

using namespace std;

class Account {
private:
	string name;
	double balance;
	int transaction_count{0};
	bool overdraft_state;				// true if balance is below 0, false if above zero.
	static int num_accounts_created;			// keep track of accounts created, should update the number appropiately.

public:
	Account bank_account() {					// constructor that takes no parameters.
		name = "no name";
		balance = 0;
		num_accounts_created++;				// new account was created + 1 to number of accounts.
	}
	Account bank_account(string tempName, int tempBalance) {			// contructor that takes 2 parameters: Name, Balance.
		name = tempName;
		balance = tempBalance;
		num_accounts_created++;				// new account was created + 1 to number of accounts.
	}

	
	
	void setName(string);				// set name of the object
	string getName();					// get name of the object
	void setBalance(double);			// set balance and it passes in the amount
	double getBalance();				// gets the objects balance
	void setTransactionCount(int);		// sets the objects transaction count by passing in the transaction value.
	int getTransactionCount();			// gets the objects transaction count.
	void setOverdraftState(double);		// sets the objects overdraft state by passing in the balance.
	bool getOverdraftState();			// gets the objects overdraft state.
	double deposit(double);				// deposits amount by passing in balance
	double withdraw(double);			// withdraws amount by passing in balance
	Account operator+(const Account & b);			// overloaded + operator to add two objects
	friend ostream& operator<<(ostream& os, const Account& b);			// overloaded << to cout an object.
};