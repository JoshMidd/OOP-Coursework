// soccer_player_test.cpp
// Josh Middleton
// 2/14/19
// 


#include <iostream>
#include "SoccerPlayer.h"

using namespace std;

SoccerPlayer::SoccerPlayer(string playerFirstName, string playerLastName, int playerJerseyNumber, string playerPosition, double playerYearlySalary) {
	SoccerPlayer::setFirstName(playerFirstName);
	SoccerPlayer::setLastName(playerLastName);
	SoccerPlayer::setJerseyNumber(playerJerseyNumber);
	SoccerPlayer::setPlayerPosition(playerPosition);
	SoccerPlayer::setYearlySalary(playerYearlySalary);
}


void SoccerPlayer::setFirstName(string playerFirstName) {
	firstName = playerFirstName;
}

string SoccerPlayer::getFirstName() {
	return firstName;
}

// function to set player last name 
void SoccerPlayer::setLastName(std::string playerLastName) {
	lastName = playerLastName;
}

// function to retrieve player last name
string SoccerPlayer::getLastName() {
	return lastName;
}

// function to set player jersey number
void SoccerPlayer::setJerseyNumber(int playerJerseyNumber) {
	if (playerJerseyNumber >= 1 && playerJerseyNumber <= 100) {
		jerseyNumber = playerJerseyNumber;
	}
	else {
		jerseyNumber = 0;
	}
}

// function to get jersey number
int SoccerPlayer::getJerseyNumber() {
	return jerseyNumber;
}

// function to set player position
void SoccerPlayer::setPlayerPosition(std::string playerPosition) {
	position = playerPosition;
}

// function to get player position
string SoccerPlayer::getPlayerPosition() {
	return position;
}

// function to set player yearly salary
void SoccerPlayer::setYearlySalary(double playerYearlySalary) {
	if (playerYearlySalary > 0) {
		yearlySalary = playerYearlySalary;
	}
	else {
		yearlySalary = 0;
	}
}

// function to get player yearly salary
double SoccerPlayer::getYearlySalary() {
	return yearlySalary;
}

// function to get weekly salary
double SoccerPlayer::getWeeklySalary() {
	weeklySalary = yearlySalary / 52;
	return weeklySalary;
}

int main() {

	SoccerPlayer player1("Jay", "Messi", 1, "Pos1", 10000.50);
	SoccerPlayer player2("", "", 0, "", 0);
	player2.setFirstName("John");
	player2.setLastName("Smith");
	player2.setJerseyNumber(2);
	player2.setPlayerPosition("Pos2");
	player2.setYearlySalary(537.90);

	cout << endl;
	cout << endl << "Displaying Player 1 Info: ";
	cout << endl << "Player 1 Name: " << player1.getFirstName() << " " << player1.getLastName();
	cout << endl << "Player 1 Jersey Number: " << player1.getJerseyNumber();
	cout << endl << "Player 1 Yearly Salary: $" << player1.getYearlySalary();
	cout << endl << "Player 1 Weekly Salary: $" << player1.getWeeklySalary();
	cout << endl;
	cout << endl << "Displaying Player 2 Info: ";
	cout << endl << "Player 2 Name: " << player2.getFirstName() << " " << player2.getLastName();
	cout << endl << "Player 2 Jersey Number: " << player2.getJerseyNumber();
	cout << endl << "Player 2 Yearly Salary: $" << player2.getYearlySalary();
	cout << endl << "Player 2 Weekly Salary: $" << player2.getWeeklySalary();


	system("pause");
	return 0;
}
