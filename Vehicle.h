#pragma once
#include<string>
#include<iostream>

//Class that stores the make, model, and year of a vehicle. Once stored the class uses the vector objects passed in from 
//the Dealership class to print out the make, model, and year of each vehicle.
class Vehicle {
public:
	//Constructor
	Vehicle();
	
	//Overload constructor
	Vehicle(std::string, std::string, int);
	
	//Getter and setter functions for make.
	std::string getMake();
	void setMake(std::string newMake);
	
	//Getter and setter functions for model.
	std::string getModel();
	void setModel(std::string newModel);

	//Getter and setter functions for year.
	int getYear();
	void setYear(int newYear);

	//Print function
	void print();

	//Destructor.
	~Vehicle();
private:
	std::string make, model;
	int year;

};