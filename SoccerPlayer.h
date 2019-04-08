// SoccerPlayer.h
// Josh Middleton
// 2/14/19
// A SoccerPlayer should include five data members 
// a first name (type string)
// a last name (type string) 
// a jersey number (type int) 
// position (type string) 
// and yearly salary (type double).

#include <string>

class SoccerPlayer {

private:
	std::string firstName;
	std::string lastName;
	int jerseyNumber;
	std::string position;
	double yearlySalary;
	double weeklySalary;

public:
	// constructer initializes soccer player first name with parameter playerFirstName
	SoccerPlayer(std::string playerFirstName, std::string playerLastName, int playerJerseyNumber, std::string playerPosition, double playerYearlySalary);

	// function to set player first name 
	void setFirstName(std::string playerFirstName);

	// function to retrieve player first name
	std::string getFirstName();

	// function to set player last name 
	void setLastName(std::string playerLastName);

	// function to retrieve player last name
	std::string getLastName();

	// function to set player jersey number
	void setJerseyNumber(int playerJerseyNumber);

	// function to get jersey number
	int getJerseyNumber();


	// function to set player position
	void setPlayerPosition(std::string playerPosition);

	// function to get player position
	std::string getPlayerPosition();


	// function to set player yearly salary
	void setYearlySalary(double playerYearlySalary);

	// function to get player yearly salary
	double getYearlySalary();

	// function to get weekly salary
	double getWeeklySalary();
};