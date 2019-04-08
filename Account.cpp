// Account.cpp
// Josh Middleton
// 4/1/19
/*
	declare class functions 
*/

#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

void Account::setName(string tempName) {								// member function to set account name.
	name = tempName;
}

string Account::getName() {								// member function to get account name.
	return name;
}

void Account::setBalance(double amount) {							// member function to set account balance.
	balance = amount;
}

double Account::getBalance() {				// member function to get account balance.
	return balance;
}

void Account::setTransactionCount(int transaction) {					// member function to set the amount of transactions per account.
	transaction_count = transaction + transaction_count;
}

int Account::getTransactionCount() {					// member function to get the amount of transactions per account.

	return transaction_count;							
}

void Account::setOverdraftState(double amount) {						// member function to set overdraft state per account.
	
	if ( amount >= 0) {
		overdraft_state = false;
	}
	else {
		overdraft_state = true;
	}
}

bool Account::getOverdraftState() {						// member function to get overdraft state per account.

	return overdraft_state;
}

double Account::deposit(double amount) {				// member function for deposits, update transaction counts and checks overdraft
	int transaction(0);
	double updatedBalance;
	updatedBalance = balance + amount;
	setBalance(updatedBalance);
	transaction++;									// track the transaction.
	setTransactionCount(transaction);				// update the amount of transactions.

	if (updatedBalance > 0) {
		Account::overdraft_state = false;
	}
	else {
		Account::overdraft_state = true;
	}

	return updatedBalance;
}

double Account::withdraw(double amount) {			// member function for withdraws, updates transactions and checks overdraft.
	int transaction(0);
	double updatedBalance;
	updatedBalance = balance - amount;
	setBalance(updatedBalance);
	transaction++;							// track the transaction.
	setTransactionCount(transaction);					// update the amount of transactions.

	if (updatedBalance > 0) {
		Account::overdraft_state = false;
	}
	else {
		Account::overdraft_state = true;
	}

	return updatedBalance;
}

Account Account::operator+(const Account& b) {				// Overload + operator to add two bank_account objects.
	Account bank_account;
	bank_account.balance = this->balance + b.balance;
	return bank_account;
}

ostream& operator<<(ostream& os, const Account& b) {			// overload << operator to print name, balance, transaction count, overdraft state. 

	os << "Account name: " << b.name << "\nAccount balance: $" << b.balance << "\n# of transactions: " << b.transaction_count << "\nOverdaft state: " << b.overdraft_state;
	return os;
}
