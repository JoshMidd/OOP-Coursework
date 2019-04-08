// budget.cpp
// Josh Middleton
// 2/21/2019
/*
Write a program that first prompts the user to enter his / her before - tax yearly income.
The program should then compute the users’ after - tax monthly income assuming the income tax is 30 %.
Print this after - tax monthly income to the console.
The program should then use a loop to continuously ask the user to enter the expense name and expense amount for monthly expenses that fall under “needs”.
You should update the total “need” expense amount at each iteration.
The user should continuously entering “need” expense name and amounts until he / she types “done” as the expense name.
You should tell the user to type “done” as the expense name to stop entering expenses.
The program should then use a loop to continuously ask the user to enter the expense name and expense amount for monthly expenses that fall under “wants”.
You should update the total “want” expense amount at each iteration.
The user should continuously entering “need” expenses until he / she types “done” as the expense name.
You should tell the user to type “done” as the expense name to stop entering expenses.
Your program should then calculate and print the actual percent toward “needs”, the actual percent
toward “wants”, and actual percent “toward” savings(assume the remaining amount after “needs” and “wants” expenses goes into savings).
Additionally, for each of these categories(“needs”, “wants”, and “savings”), you should print “Within
Budget” or “Over Budget”(using less than or equal to 50 % , 30 % , and 20 % , respectively as “Within Budget”).*/

#include <iostream>		// input, output 
#include <string>		// string	
#include <iomanip>		// set precision, setw, setfill

using namespace std;


int main() {

	string expenseName;
	long long yearlyIncome{ 0 };
	long long monthlyIncome{ 0 };
	long long yearlyIncomeTax{ 0 };
	long long expenseAmount{ 0 };
	long long needsTotal{ 0 };
	long long wantsTotal{ 0 };
	long long savingsTotal{ 0 };
	long long needsBudget{ 0 };
	long long wantsBudget{ 0 };
	long long savingsBudget{ 0 };
	
	// 1. Prompt the user to enter thier before tax yearly income.
	 
	cout << "Enter Your Yearly Income, Before Taxes.";
	cout << "\n______________________________________";
	cout << "\nEnter 100, for $1.00";
	cout << "\nEnter 1000, for $10.00";
	cout << "\nEnter 10000, for $100.00";
	cout <<  "\nEnter 100000, for $1000.00";
	cout << endl;
	cout << endl;
	cin >> yearlyIncome;

	yearlyIncomeTax = yearlyIncome * .30;				// calculate yearly income tax
	yearlyIncome = yearlyIncome - yearlyIncomeTax;		// calculate yearly income
	monthlyIncome = yearlyIncome / 12;					// calculate monthly income


	cout << "\nYour Monthly Income After Tax is: " << '$' << monthlyIncome << endl;		// print monthly income after tax to the console

	for (int i = 0; i < 20; i++) {				// loop for monthly wants expenses

		cout << "\nEnter the name for your Monthly Needs Expense, If you're done, Enter <done>" << endl;			// prompt user to enter name of expense
		cin >> expenseName;				// collect user input
		
		if (expenseName == "done") {
			break;
		}
		else {

			cout << "\nEnter " << expenseName << " amount: " << endl;
			cin >> expenseAmount;			// collects expense name
			needsTotal += expenseAmount;			// updates total expense each iteration.
		}
	}

	for (int i = 0; i < 20; i++) {			// loop for monthly wants expenses

		cout << "\nEnter the name for your Monthly Wants Expense, If you're done, Enter <done>" << endl;			// prompt user to enter name of expense
		cin >> expenseName;			// collect user input 

		if (expenseName == "done") {			// condition on the loop, enter "done" and it breaks the loop
			break;
		}
		else {

			cout << "\nEnter " << expenseName << " amount: " << endl;		// secondary condition collects more input
			cin >> expenseAmount;			// collects expense name
			wantsTotal += expenseAmount;			// updates total expense each iteration.
		}
	}

	needsBudget = monthlyIncome * .50;								// calculate Needs budget @ %50 of the Monthly Income.
	wantsBudget = monthlyIncome * .30;								// calculate Wants Budget @ %30 of the Monthly Income.
	savingsBudget = monthlyIncome * .20;							// calculate Savings Budget @ %20 of the Monthly Income.
	savingsTotal = (monthlyIncome - (needsTotal + wantsTotal));		// calculate savings total
	cout << endl;


	if (needsTotal < needsBudget) {									// check the Needs budget 
		cout << "Needs expense: Within Budget" << endl;
	}
	else {
		cout << "Needs expense: Over Budget" << endl;
	}

	if (wantsTotal < wantsBudget) {									// check the Wants budget
		cout << "Wants expense: Within Budget" << endl;
	}
	else {
		cout << "Wants expense: Over Budget" << endl;
	}

	if (savingsTotal < savingsBudget) {								// check the Savings budget
		cout << "Savings expense: Over Budget" << endl;
	}
	else {
		cout << "Savings expense: Within Budget" << endl;
	}

	
	long double actualNeedsPercentage{static_cast <long double> (needsTotal) / monthlyIncome * 100};			// calculate percentage devoted to needs
	cout << "\nThe actual Needs Percentage is: " << fixed << setprecision(2) << actualNeedsPercentage << "%" << endl;	// print percentage to console		


	long double actualWantsPercentage{static_cast <long double> (wantsTotal) / monthlyIncome * 100};			// calculate percentage devoted to wants
	cout << "\nThe actual Wants Percentage is: " << fixed << setprecision(2) << actualWantsPercentage << "%" << endl;	// print percentage to console


	long double actualSavingsPercentage{ static_cast <long double> (savingsTotal) / monthlyIncome * 100 };			// calculate percentage devoted to savings
	cout << "\nThe actual Savings Percentage is: " << fixed << setprecision(2) <<  actualSavingsPercentage << "%" << endl;	// print percentage to console

	
	system("pause");		// Keep the display on the console.
	return 0; 
}