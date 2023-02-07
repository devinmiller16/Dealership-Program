#include<iostream>
#include"Vehicle.h"

using namespace std;

//Constructor
Vehicle::Vehicle() {}

//Destructor
Vehicle::~Vehicle() {}

//Overload constructor that sets the make, model, and year.
Vehicle::Vehicle(string carMake, string carModel, int carYear) {
	make = carMake;
	model = carModel;
	year = carYear;
}

//Returns the vehicles make.
string Vehicle::getMake() {
	return make;
}

//Sets the make of a new vehicle.
void Vehicle::setMake(string newMake) {
	make = newMake;
}

//Returns the vehicle model.
string Vehicle::getModel() {
	return model;
}

//Sets the model of a new vehicle.
void Vehicle::setModel(string newModel) {
	model = newModel;
}

//Returns the vehicle year.
int Vehicle::getYear() {
	return year;
}

//Set the year of a new vehicle.
void Vehicle::setYear(int newYear) {
	year = newYear;
}

//Prints the make, model, and year of a vehicle.
void Vehicle::print() {
	cout << "Make: " << make << endl;
	cout << "Model: " << model << endl;
	cout << "Year: " << year << endl << endl;
}