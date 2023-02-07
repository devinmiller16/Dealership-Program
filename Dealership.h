#pragma once
#include<string>
#include<vector>
#include<iostream>
#include"Vehicle.h"

//Class that contains the functions to add vehicles, list vehicles, and stores/gets the name and capacity of the dealership.
class Dealership {
public:
	//Default Constructor
	Dealership();

	//Overload Constructor
	Dealership(std::string dealershipName, int numOfVehicles);

	//Function that adds a vehicle to the vector.
	void addVehicle();
	
	//Sets dealership name.
	void setDealershipName(std::string);

	//Sets capacity.
	void setNumOfVehicles(int);

	//Returns dealership name.
	std::string getDealershipName();

	//Returns capacity.
	int getNumOfVehicles();

	//Lists the vehicles in the vector.
	void listVehicles();

	//Destructor
	~Dealership();
private:
	std::string dName;
	int capacity;
	std::vector<Vehicle> vehicles; //Vector that contains the vehicle objects.
};