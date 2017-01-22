//Calculate Cabinet Doors Price

//get type of door: 101, 102, 103
//get type of wood: red oak, maple, mdf
//check if installation fee = 250/hr
//check if delivery charge = 100
//get quantity: 1-500
//Calculate quantity * (type of wood + type of door)
//show total for one door
//Calculate total for order: sum total for each door
//Show total for order
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>


//Constants
//Constants Type of Doors
const double door101 = 25.00;
const double door102 = 45.00;
const double door103 = 60.00;

//Constants Type of Wood
const double typeMaple = 20.00;
const double typeAsh = 30.00;
const double typeMdf = 15.00;

//Constants extra services
const double deliveryCharge = 100.00;
const double installationFee = 250.00;



using namespace std;


int main() {
	//Variables
	int accountNum;
	int typeOfDoor;
	string typeOfWood;
	string doInstall;
	string doDelivery;
	int numOfDoors;

	double doorCost;
	double deliver;
	double install;
	double costOfWood;
	double totalPerDoor;
	double totalOfOrder;
	double runningTotal = 0;

	//declare input file stream
	ifstream inFile;
	//declare output file stream
	ofstream outFile;

	//open input file
	inFile.open("order.txt");
	//open output file
	outFile.open("billDCD.txt");

	outFile << fixed << showpoint;
	outFile << setprecision(2);

	if (inFile.is_open()) {

		inFile >> accountNum >> doInstall >> doDelivery;
		cout << "account num: " << accountNum;
		cout << "install: " << doInstall;
		cout << "delivery: " << doDelivery;

		if (doInstall == "Install") {
			install = installationFee;
		}
		else
			install = 0.00;

		if (doDelivery == "Deliver") {
			deliver = deliveryCharge;
		}
		else
			deliver = 0.00;

		while (inFile.good())
		{
			
			inFile >> typeOfDoor;
			cout << "type of door: " << typeOfDoor;

		

			//Door 101 
			if (typeOfDoor == 101) {
				inFile >> typeOfWood >> numOfDoors;

				if (typeOfWood == "Maple") {
					costOfWood = typeMaple;
				}
				else if (typeOfWood == "Ash") {
					costOfWood = typeAsh;
				}
				else if (typeOfWood == "Mdf") {
					costOfWood = typeMdf;
				}
				else
					cout << "Error: type of Wood not found. Review Order" << endl;
				doorCost = door101;
				totalPerDoor = numOfDoors * (costOfWood + doorCost);

				//output amount due for specified door
				outFile << "Type of Door: " << typeOfDoor;
				outFile << "  Quantity: " << numOfDoors;
				outFile << "  Type of Wood: " << typeOfWood << endl;
				outFile << "Total for Door(s): $" << setw(6) << totalPerDoor << endl;
			}

			//Door 102
			else if (typeOfDoor == 102) {
				inFile >> typeOfWood >> numOfDoors;

				if (typeOfWood == "Maple") {
					costOfWood = typeMaple;
				}
				else if (typeOfWood == "Ash") {
					costOfWood = typeAsh;
				}
				else if (typeOfWood == "Mdf") {
					costOfWood = typeMdf;
				}
				else
					cout << "Error: type of Wood not found. Review Order" << endl;
				doorCost = door102;
				totalPerDoor = numOfDoors * (costOfWood + doorCost);

				//output amount due for specified door
				outFile << "Type of Door: " << typeOfDoor;
				outFile << "  Quantity: " << numOfDoors;
				outFile << "  Type of Wood: " << typeOfWood << endl;
				outFile << "Total for Door(s): $" << setw(6) << totalPerDoor << endl;
			}

			//Door 103
			else if (typeOfDoor == 103) {
				inFile >> typeOfWood >> numOfDoors;

				if (typeOfWood == "Maple") {
					costOfWood = typeMaple;
				}
				else if (typeOfWood == "Ash") {
					costOfWood = typeAsh;
				}
				else if (typeOfWood == "Mdf") {
					costOfWood = typeMdf;
				}
				else
					cout << "Error: type of Wood not found. Review Order" << endl;
				
				doorCost = door103;
				totalPerDoor = numOfDoors * (costOfWood + doorCost);

				//output amount due for specified door
				outFile << "Type of Door: " << typeOfDoor;
				outFile << "  Quantity: " << numOfDoors;
				outFile << "  Type of Wood: " << typeOfWood << endl;
				outFile << "Total for Door(s): $" << setw(6) << totalPerDoor << endl;

				
			}

			else
				cout << "Error finding door, Please review Order file." << endl;
			runningTotal = runningTotal + totalPerDoor;
		}//end of while
	}//end of if
	totalOfOrder = runningTotal + install + deliver;

		//output Total of order
		outFile << endl;
		outFile << "Account Number: " << accountNum << endl;
		outFile << "Delivery Fee: $" << deliver << endl;
		outFile << "Installation Fee: $" << install << endl;
		outFile << endl;
		outFile << "Total for Order: $" << setw(6) << totalOfOrder << endl;

		
		

		cout << "Bill has been created for Account: " << accountNum << endl;
		system("pause");
		return 0;

}//end of main
