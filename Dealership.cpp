#include<iostream>
#include"Dealership.h"
#include<vector>
#include<string>

using namespace std;

//Constructor
Dealership::Dealership() {}

//Deastructor
Dealership::~Dealership() {}

//Sets the private members of dName and capacity equal to the objects that have been passed in by the users input.
Dealership::Dealership(string dealershipName, int numOfVehicles) {
	dName = dealershipName;
	capacity = numOfVehicles;
}

//Sets the dealership name.
void Dealership::setDealershipName(string nameOfDealership) {
	dName = nameOfDealership;
}

//Sets the capacity.
void Dealership::setNumOfVehicles(int lotCapacity) {
	capacity = lotCapacity;
}

//Function that adds a vehicle to the vector vehicles.
void Dealership::addVehicle() {

	string carMake, carModel;
	int carYear;

	cout << "Enter the vehicle make: "; //Prompts the user to enter the make.
	cin >> carMake;
	while (cin.fail() || carMake.size() == 0 || string::npos != carMake.find_first_of("0123456789") || carMake.size() < 2) {
		if (carMake.size() == 0) { //If the name includes no characters.
			cout << "ERROR! You must enter a valid vehicle make. Please try again: ";
		}
		else if (string::npos != carMake.find_first_of("0123456789")) { //If the name includes numbers 
			cout << "ERROR! Vehicle make must not include numbers. Please try agian: ";
		}
		else if (carMake.size() < 2) { //If the name is less than 2 characters.
			cout << "ERROR! Vehicle make cannot be less than 2 characters. Please try again: ";
		}
		cin.clear();
		cin >> carMake;
	}

	cout << "Enter the vehicle model: "; //Prompts the user to enter the model.
	cin >> carModel;
		
	cout << "Enter the vehicle year: "; //Prompts the user to enter the year.
	cin >> carYear;
	while (cin.fail() || carYear < 1900) { //If the lot capacity is less than zero or if the user does not enter in a number.
		if (cin.fail()) {
			cout << "You must enter a number. Please try again: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cout << "The number you entered was lower than 1900. Please try again: ";
		}
		cin >> carYear;
	}
	cout << endl;

	Vehicle vehicle(carMake, carModel, carYear); //Once the user enter in the information it is then passed to the Vehicle class constructor.
	vehicles.push_back(vehicle); //Adds the vehicle object to the vector.
	cout << "The vehicle has been added to your inventory!" << endl << endl; //Prints out a message so the user knows the vehicle has been added.
}

//Function that prints the data with the help of the Vehicle class.
void Dealership::listVehicles() {

	for (Vehicle v : vehicles) //Ranged based for-loop that invokes the print function from the Vehicle class for each object in the vector.
	{
		v.print();
	}
}

//Function that returns the name of the dealership.
string Dealership::getDealershipName() {
	return dName;
}

//Function that returns the capacity of the lot. 
int Dealership::getNumOfVehicles() {
	return capacity;
}
