//<Programming Assignment 4> -- Allows users to store the make, model, and year of vehcles until the lot is full.
//CSIS 112-<D01>
//<Citations if necessary> -- Example code used from "C++ Programming Assignment Instructions" by Terri Sipantzi.
//Vector object help from -- http://www.cplusplus.com/forum/beginner/63543/ 
//More vector  help from Mike McMillian - https://levelup.gitconnected.com/learning-c-storing-class-objects-in-containers-ca12546f1a89

#include<iostream>
#include"Dealership.h"

using namespace std;

int main()
{
	Dealership dealership1;
	string nameOfDealership;
	int lotCapacity, vehiclesOnLot = 0; //Current lot capacity is set to zero.
	char selection;
	bool go = true;

	cout << "Devin Miller - Assignment 4" << endl << endl;

	cout << "Enter the name of the dealership: "; //Prompts the user to enter in the name of the dealership.
	getline(cin, nameOfDealership); //The stream captures the entire name of the dealership.
	cout << endl;
	//If the user enters in a name with no characters, characters less than 2, or a name that includes numbers the corresponding error will occur
	//the input stream will clear and the user will then be prompted to enter in a new dealership name.  
	while (cin.fail() || nameOfDealership.size() == 0 || string::npos != nameOfDealership.find_first_of("0123456789") || nameOfDealership.size() < 2) {
		if (nameOfDealership.size() == 0) { //If the name includes no characters.
			cout << "ERROR! You must enter the name of the dealership. Please try again: ";
		}
		else if (string::npos != nameOfDealership.find_first_of("0123456789")) { //If the name includes numbers 
			cout << "ERROR! Dealership name must not include numbers. Please try agian: ";
		}
		else if (nameOfDealership.size() < 2) { //If the name is less than 2 characters.
			cout << "ERROR! Dealership name cannot be less than 2 characters. Please try again: ";
		}
		cin.clear();
		cin >> nameOfDealership;
	}
	dealership1.setDealershipName(nameOfDealership); //Once error checking is complete the name of the dealership is passed into the setDealershipName function of the class Dealership.

	cout << "Enter the lot capacity: "; //Prompts the user to enter the capacity of the dealership.
	cin >> lotCapacity;
	cout << endl;
    //function for error checking.
	while (cin.fail() || lotCapacity < 0) { //If the lot capacity is less than zero or if the user does not enter in a number.
		if (cin.fail()) {
			cout << "You must enter a number. Please try again: ";
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cout << "The number you entered was negative. Please try again: ";
		}
		cin >> lotCapacity;
	}
	dealership1.setNumOfVehicles(lotCapacity); //Once error checking is complete the lot capacity is passed into the setNumOfVehicles function of the class Dealership.

	while (go) { //Loop that executes as long as go remains true. (which is always.)
		//Outputs the main menu
		cout << "Main Menu" << endl << endl;
		cout << "A - Add a new Vehicle" << endl << endl;
		cout << "L - List vehicles" << endl << endl;
		cout << "Q - Quit" << endl << endl;
		cout << "Selection: "; //Asks for the users selection
		cin >> selection;
		cout << endl;
		
			switch (selection) {
			case 'A': //If the user selects A
				//Loop that executes as long as the vehicles on the lot is less than the number of the capacity of the lot.
				if (vehiclesOnLot < dealership1.getNumOfVehicles()) { //Uses the getNumOfVehicles function of the class Dealership to check the capacity of the lot and compares it to the vehicles currently on the lot.
					dealership1.addVehicle(); //If the vehicles on the lot is less than the capacity then the addVehicle funtion of the class Dealership is invoked. 
					vehiclesOnLot++; //Once one vehicle is added the vehicles on the lot is increased by one. 
				}
				else { //If the vehicles on the lot is not less than the capacity of the lot then the user is unable to add more vehicles to the inventory.
					cout << "Unable to add more vehicles. Lot is full!" << endl << endl;
				}
				break;
			case 'L': //If the user selects L.
				//If there are no vehicles on the lot.
				if (vehiclesOnLot == 0)
					cout << "There are no vehicles currently in your Inventory!" << endl << endl;
				else //If there are vehicles on the lot then the printData function of class Dealership is invoked.
					dealership1.listVehicles();
				break;
			case 'Q'://If the user selects Q.
				cout << "Exiting program ..... " << endl;
				system("Pause");
				return 0; //Quits the program.
			default: //If neither A, L, or Q is entered an invalid input message occurs.
				cout << "Invalid input! Please try again." << endl << endl;
			}
	}
	system("pause");
	return 0;
}