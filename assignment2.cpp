/* 
* \file assinment2.cpp
* \author Reese Karlunchuck (s0566214)
* \date 08/10/2025
* \brief This program allows a server (person running the program) to serve tables depening on the day, time, and age of the customer.
*/
#include <iostream> //need input and output
#include <iomanip> //needed to show 2 decimal place for the price
#include <string> //needed for the print function as it would save a lot of if statements
using namespace std;

// create your function declarations (prototypes) here:/
void welcome();
double getDay(char& day1, char& day2);
string convertFullDayName(char day1, char day2);
double getTime(int& hours, char& colon, int& minutes);
void getAgeGroup(char& age, double& discount, string& customerType);
void addTotal(double& totalCost, double initialCost, double discount, double weekend);
void printTotal(string customerType, int hours, int minutes, string fullDayName, double totalCost);

int main() {
	//set all needed variables to (they will change later in the functions
	char day1 = '0', day2 = '0', age = '0', colon = '0';
	double weekend = 0, initialCost = 0;
	int hours = 0, minutes = 0;
	string fullDayName = "";
	string customerType = "";
	double discount = 0;
	double totalCost = 0;

	//set the loop so it will run at least once
	char playAgain = 'N';

	do {
		/*
		* @brief Welcome the user into the code 
		*/
		welcome();

		/*
		* @brief recieve input from the user to get the day and get the price increase for the calculate function
		* param[in] char day1
		* param[in] char day1
		*/
		weekend = getDay(day1, day2);

		/*
		* @brief converts the day into a string so it can be printed easier later
		* param[in] char day1
		* param[in] char day2
		*/
		fullDayName = convertFullDayName(day1, day2);

		/*
		* @brief Get the time of the input to decide whether it is breakfast, lunch, or supper
		* param[in] int hours
		* param[in] char colon
		* param[in] int minutes
		*/
		initialCost = getTime(hours, colon, minutes);

		/*
		* @brief Find the customers age group and apply discounts depending on the age
		* param[in] char age
		* param[in] double discount
		*/
		getAgeGroup(age, discount, customerType);

		/*
		* @brief Find the total cost of the whole meal using all of the functions that we defined prior
		* param[in] double totalCost
		* param[in] double initialCost
		* param[in] double discount
		* param[in] double weekend
		*/
		addTotal(totalCost, initialCost, discount, weekend);

		/*
		* @brief
		* param
		* param
		*/
		printTotal(customerType, hours, minutes, fullDayName, totalCost);

		cout << "Would you like to serve another customer (Y to serve again): ";
		cin >> playAgain; //Ask the user if they would like to run the code again
		cout << endl;
		cin.ignore(256, '\n'); //Ignore so the date is not accidenly entered when looping the program if you put extra characters
	} while (playAgain == 'Y' || playAgain == 'y'); //end the loop if the user types Y or y
	return 0;
}

// write your supporting functions below here
void welcome() {
	cout << "Welcome to Jimmy's Buffet " << endl; //Introduce user to the code
	cout << "Cost calculator by Reese Karlunchuck (s0566214)." << endl;
	cout << "-------------------------------------------------" << endl;
}
double getDay(char& day1, char& day2) {
	cout << "What day is it today (First two letters only): "; 
	cin >> day1 >> day2; //Tell user how to format input and collect input

	if (cin.fail()) { //delete and ignore input because it cause input to fail
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Not in day database. Please try again" << endl; //Tell user they did the input wrong and to try again
		return getDay(day1, day2); //Run the function again to get a good input
	}

	if (day1 == 'M' && day2 == 'O' || day1 == 'M' && day2 == 'o' || day1 == 'm' && day2 == 'O' || day1 == 'm' && day2 == 'o' || day1 == 'T' && day2 == 'U' || day1 == 'T' && day2 == 'u' || day1 == 't' && day2 == 'U' || day1 == 't' && day2 == 'u' || day1 == 'W' && day2 == 'E' || day1 == 'W' && day2 == 'e' || day1 == 'w' && day2 == 'E' || day1 == 'w' && day2 == 'e' || day1 == 'T' && day2 == 'H' || day1 == 'T' && day2 == 'h' || day1 == 't' && day2 == 'H' || day1 == 't' && day2 == 'h' || day1 == 'F' && day2 == 'R' || day1 == 'F' && day2 == 'r' || day1 == 'f' && day2 == 'R' || day1 == 'f' && day2 == 'r') {
		cin.ignore(256, '\n'); //Ignore so it doesnt automatically call the next input invalid if they type the whole day
		return 0.0; //get the input as a weekday (this will be used in the calculate function, but won't change the answer as it is 0)
	}

	else if (day1 == 'S' && day2 == 'A' || day1 == 'S' && day2 == 'a' || day1 == 's' && day2 == 'A' || day1 == 's' && day2 == 'a' || day1 == 'S' && day2 == 'U' || day1 == 'S' && day2 == 'u' || day1 == 's' && day2 == 'U' || day1 == 's' && day2 == 'u') {
		cin.ignore(256, '\n'); //Ignore so it doesnt automatically call the next input invalid if they type the whole day
		return 0.10; //get input as a weekend day and get the extra charge for the weekend buffet (will be used in calculate function)
	}

	else {
		cin.clear(); //delete and ignore the input
		cin.ignore(256, '\n');
		cout << "Not in day database. Please try again" << endl; //Tell user they did the input wrong and to try again
		return getDay(day1, day2); //run the function again to get a valid input
	}
}

string convertFullDayName(char day1, char day2) {
	if (day1 == 'M' && day2 == 'O' || day1 == 'M' && day2 == 'o' || day1 == 'm' && day2 == 'O' || day1 == 'm' && day2 == 'o')
		return "Monday"; //Get string for Monday using the day1 and day2 inputs from getDay (these will be used in the print function

	else if (day1 == 'T' && day2 == 'U' || day1 == 'T' && day2 == 'u' || day1 == 't' && day2 == 'U' || day1 == 't' && day2 == 'u')
		return "Tuesday"; //Get string for Tuesday using the day1 and day2 inputs from getDay (these will be used in the print function

	else if (day1 == 'W' && day2 == 'E' || day1 == 'W' && day2 == 'e' || day1 == 'w' && day2 == 'E' || day1 == 'w' && day2 == 'e')
		return "Wednesday"; //Get string for Wednesday using the day1 and day2 inputs from getDay (these will be used in the print function

	else if (day1 == 'T' && day2 == 'H' || day1 == 'T' && day2 == 'h' || day1 == 't' && day2 == 'H' || day1 == 't' && day2 == 'h')
		return "Thursday"; //Get string for Thursday using the day1 and day2 inputs from getDay (these will be used in the print function

	else if (day1 == 'F' && day2 == 'R' || day1 == 'F' && day2 == 'r' || day1 == 'f' && day2 == 'R' || day1 == 'f' && day2 == 'r')
		return "Friday"; //Get string for Friday using the day1 and day2 inputs from getDay (these will be used in the print function

	else if (day1 == 'S' && day2 == 'A' || day1 == 'S' && day2 == 'a' || day1 == 's' && day2 == 'A' || day1 == 's' && day2 == 'a')
		return "Saturday"; //Get string for Saturday using the day1 and day2 inputs from getDay (these will be used in the print function

	else if (day1 == 'S' && day2 == 'U' || day1 == 'S' && day2 == 'u' || day1 == 's' && day2 == 'U' || day1 == 's' && day2 == 'u')
		return "Sunday"; //Get string for Sunday using the day1 and day2 inputs from getDay (these will be used in the print function

	else
		return "invalid"; //Shouldn't be possible but have a backup day just incase somthing goes wrong
}

double getTime(int& hours, char& colon, int& minutes) {
	cout << "When did the customer arrive (24 hour format ex 5:30pm is 17:30): ";
	cin >> hours >> colon >> minutes; //Give user instructions on how to format input and recieve the input

	if (cin.fail() || hours > 24 || hours < 1 || minutes > 60 || minutes < 0) { //Delete and ignore all input as it was done wrong
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Input is not in range or not put in correctly please try again:" << endl; //inform the user that they did the input wrong and have to try again
		return getTime(hours, colon, minutes); //Run the function again to get a better input
	}
	else if (hours > 5 && hours < 11 || hours == 11 && minutes <= 30) {
		cin.ignore(256, '\n'); //Ignore so it doesnt automatically call the next input invalid or get age early
		return 15.95; //Get initial price for breakfast
	} 

	else if (hours == 11 && minutes > 30 || hours > 11 && hours < 17 || hours == 17 && minutes <= 30) {
		cin.ignore(256, '\n'); //Ignore so it doesnt automatically call the next input invalid or get age early
		return 19.95; //Get initial price for lunch
	}

	else if (hours == 17 && minutes > 30 || hours > 17 && hours < 22 || hours == 22 && minutes == 0) {
		cin.ignore(256, '\n'); //Ignore so it doesnt automatically call the next input invalid or get age early
		return 27.95; //Get initial price for Dinner
	}

	else {
		cin.clear();
		cin.ignore(256, '\n'); //Ignore so it doesnt automatically call the next input invalid or get age early
		cout << "The buffet is closed at this time please enter a valid time " << endl; //tell user that the buffet is closed and to enter a valid time
		return getTime(hours, colon, minutes); //Have user try again to say a time during buffet hours
	}
}

void getAgeGroup(char& age, double& discount, string& customerType) {
	cout << "What age group of customer are you? ([A]dult, [C]hild, [S]enior): "; //Get the users age group
	cin >> age;

	if (cin.fail()) {//ignore and delete input if it makes cin fail
		cin.clear();
		cin.ignore(256, '\n');
		cout << "That is not a valid age group make sure you only put one letter"; //tell the user their input didnt work and to retry it
		return getAgeGroup(age, discount, customerType); //run the function again
	}

	else if (age == 'A' || age == 'a') { //Check if customer is an Adult
		cin.ignore(256, '\n'); //Ignore so it doesnt automatically end or restart the loop
		discount = 0.00; //Enter the total discount for adults (nothing)
		customerType = "Adult"; //Set customer type to adult (will be used in the print function later)
	}

	else if (age == 'C' || age == 'c') { //Check if customer is a Child
		cin.ignore(256, '\n'); //Ignore so it doesnt automatically end or restart the loop
		discount = 0.50; //Enter the total discount for children
		customerType = "Child"; //Set customerType to child (will be used in the print function later)
	}

	else if (age == 'S' || age == 's') { //Check if customer is a Senior
		cin.ignore(256, '\n'); //Ignore so it doesnt automatically end or restart the loop
		discount = 0.25; //Enter the total discount for Seniors
		customerType = "Senior"; //Set customerType to Senior (will be used in the print functio later)
	}

	else { //delete and ignore any inputs as they were not what the program was looking for
		cin.clear();
		cin.ignore(256, '\n'); 
		cout << "That is not a valid age group make sure you only put one letter. Please try again" << endl; //tell the user their input didnt work and to retry it
		return getAgeGroup(age, discount, customerType); //Call the function again so the input will be done correctly this time
	}
}

void addTotal(double& totalCost, double initialCost, double discount, double weekend) {
	discount = initialCost * discount; //Get the value of of the discount by multiplying the percentage by the price
	weekend = initialCost * weekend; //Get the value of the weekend by multiplying the percentage by the price (if weekday will == 0)
	totalCost = initialCost - discount + weekend; //Subtract the discount and add the weekend to initial price to get the total cost
}

void printTotal(string customerType, int hours, int minutes, string fullDayName, double totalCost) {
	cout << fixed << setprecision(2); //make the decimals only two places because its money (don't have to change back as price is the only thing with decimals
	cout << "================================" << endl;
	cout << "Thank you for dining at Jimmy's" << endl;
	cout << "Here is your bill:" << endl;
	cout << "One " << customerType << " at " << hours << ":" << setw(2) << setfill('0') << minutes << " on " << fullDayName << " will be  $" << totalCost << endl; //Print the final price setw(2) and setfill('0') makes there be at least 2 thinks printed in minutes and it will default to a 0 this is needed because normally only 1 0 would be printed if you did a time like 12:00 or 12:05
}
