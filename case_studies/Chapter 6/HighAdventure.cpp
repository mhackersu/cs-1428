// This program will assist the High Adventure Travel Agency
// in calculating the costs of their four major vacation packages.

#include <iostream>
#include <iomanip>
using namespace std;

// Constants for the charges            Per person 
const double CLIMB_RATE = 350.0;        // Base rate - Devil's Courthouse
const double SCUBA_RATE = 1000.0;       // Base rate - Bahamas Scuba
const double SKY_DIVE_RATE = 400.0;     // Base rate - Sky diving
const double CAVE_RATE = 700.0;         // Base rate - Spelunking
const double CLIMB_INSTRUCT = 100.0;    // Climbing instruction
const double SCUBA_INSTRUCT = 100.0;    // Scuba instruction
const double LODGE1_RATE = 65.0;        // Lodging option 1 (sky diving)
const double LODGE2_RATE = 120.0;       // Lodging option 2 (sky diving)
const double TENT_RATE = 40.0;          // Tent rental per tent
const double DEPOSIT_RATE = 0.50;
const double GROUP_DISCOUNT_RATE = 0.10;      

// Function prototypes
void climbing();
void scuba();
void skyDive();
void spelunk();
int menu();
void holdScreen();

int main()
{
	int selection;

	cout << fixed << showpoint << setprecision(2);
	do
	{
     	selection = menu();
		switch(selection)
		{
			case 1 :	climbing();
						break;
			case 2 :	scuba();
						break;
			case 3 :	skyDive();
						break;
			case 4 :	spelunk();
						break;
			case 5 :	cout << "Exiting program.\n\n";
		}
	} while (selection != 5);
	return 0;
}

/*******************************************************
 *                      menu                           *
 * Displays the main menu and gets the user's choice.  *
 * Returns a valid integer in the range 1 - 5.         *
 *******************************************************/
int menu()
{
	int choice;

	cout << "High Adventure Travel Agency\n";
	cout << "----------------------------\n";
	cout << "1) Devil's Courthouse Adventure Weekend\n";
	cout << "2) Scuba Bahama\n";
	cout << "3) Sky-Dive Colorado\n";
	cout << "4) Barron Cliff Spelunk\n";
 	cout << "5) Exit Program\n\n";
	
	cin  >> choice;
	while (choice < 1 || choice > 5)  // Validate input
	{
		cout << "Invalid Selection. Enter 1, 2, 3, 4, or 5: ";
		cin  >> choice;
	}
	return choice;
}

/**************************************************
 *                    climbing                    *
 * This function calculates the charges for the   *
 * Devil's Courthouse Adventure Weekend package.  *
 **************************************************/
void climbing()
{
	const int NUM_DAYS = 3;    // Length of this trip
	int    beginners,          // Clients needing instruction
		   advanced,           // Clients not needing instruction
		   tentsNeeded;        // Number of tents being rented
	double baseCharges,        // Base charge for the entire group
		   instructionChgs,    // Total instruction cost
		   tentChgs,           // Total tent rental cost
		   totalChgs,          // Total charges
		   discount = 0.0,	   // Discount amount
		   deposit;            // Required deposit

	cout << "\nDevil's Courthouse Adventure Weekend\n";
	cout << "------------------------------------\n";
	cout << "How many will be going who need an instructor? ";
	cin  >> beginners;
	cout << "How many advanced climbers will be going? ";
	cin  >> advanced;
	cout << "How many tents (sleep 4) do you want to rent? ";
	cin  >> tentsNeeded; 

	// Calculate base charges
	baseCharges = (beginners + advanced) * CLIMB_RATE;
	totalChgs = baseCharges;

	// Calculate discount for 5 or more 
	if ((beginners + advanced) > 4)
	{   
	   discount = (totalChgs * GROUP_DISCOUNT_RATE);
	   totalChgs -= discount;
	}
	// Add cost of instruction
	instructionChgs = beginners * CLIMB_INSTRUCT;
	totalChgs += instructionChgs;

	// Add cost of tent rental
	tentChgs = tentsNeeded * TENT_RATE * (NUM_DAYS - 1);
	totalChgs += tentChgs;

	// Calculate required deposit
	deposit = totalChgs * DEPOSIT_RATE;
	
	// Display Charges 
	cout << "\nNumber in party:  " << (beginners + advanced); 
	cout << endl;
	cout << "Base charges:     $" << setw(8) << baseCharges << endl;
	cout << "Instruction cost: $" << setw(8) << instructionChgs << endl;
	cout << "Tent Rental:      $" << setw(8) << tentChgs << endl;
	cout << "Discount:         $" << setw(8) << discount << endl;
	cout << "Total Charges:    $" << setw(8) << totalChgs << endl;
	cout << "Required Deposit: $" << setw(8) << deposit << endl << endl;
	holdScreen();
}

/*************************************************
 *                scuba function                 *
 * This function calculates the charges for the  *
 * Scuba Bahama package.                         *
 *************************************************/
void scuba()
{   
	int    beginners,          // Clients needing instruction
		   advanced;           // Clients not needing instruction
	double baseCharges,        // Base charge for the entire group
		   instructionChgs,    // Total instruction cost
		   totalChgs,          // Total charges
		   discount = 0.0,     // Discount amount
		   deposit;            // Required deposit

	cout << "\nScuba Bahama\n";
	cout << "------------------------------------\n";
	cout << "How many will be going who need an instructor? ";
	cin  >> beginners;
	cout << "How many advanced scuba divers will be going? ";
	cin  >> advanced;

	// Calculate base charges
	baseCharges = (beginners + advanced) * SCUBA_RATE;
	totalChgs = baseCharges;

	// Calculate discount for 5 or more
	if ((beginners + advanced) > 4)
	{
		discount = (totalChgs * GROUP_DISCOUNT_RATE);
		totalChgs -= discount;
	}
	// Add cost of instruction
	instructionChgs = beginners * SCUBA_INSTRUCT;
    totalChgs += instructionChgs;

	// Calculate required deposit
	deposit = totalChgs * DEPOSIT_RATE;
	
	// Display Charges 
	cout << "\nNumber in party:  " << (beginners + advanced); 
	cout << endl;
	cout << "Base charges:     $" << setw(8) << baseCharges << endl;
	cout << "Instruction cost: $" << setw(8) << instructionChgs << endl;
	cout << "Discount:         $" << setw(8) << discount << endl;
	cout << "Total Charges:    $" << setw(8) << totalChgs << endl;
	cout << "Required Deposit: $" << setw(8) << deposit << endl << endl;
	holdScreen();
}

/*************************************************
 *                  skyDive                      *
 * This function calculates the charges for the  *
 * Sky-Dive Colorado package.                    *
 *************************************************/
void skyDive()
{
	const int NUM_DAYS = 4;  // Length of this trip
	int    party,			 // Number in party
		   lodge1,			 // Number at 1st lodging choice
	       lodge2;			 // Number at 2nd lodging choice
	double baseCharges,	     // Base charge for the entire group
	       lodgingChgs,      // Total lodging cost
	 	   totalChgs,        // Total charges
		   discount = 0.0,	 // Discount amount
	       deposit;          // Required deposit

	cout << "\nSky-Dive Colorado\n";
	cout << "------------------------------------\n";
	cout << "How many will be going? ";
	cin  >> party;

	// Calculate base charges
	baseCharges = party * SKY_DIVE_RATE;
	totalChgs = baseCharges;

	// Calculate discount for 5 or more
	if (party > 4)
	{
		discount = (totalChgs * GROUP_DISCOUNT_RATE);
		totalChgs -= discount;
	}
	// Calculate lodging costs
	cout << "How many will stay at Wilderness Lodge? ";
	cin  >> lodge1;
	cout << "How many will stay at Luxury Inn? ";
	cin  >> lodge2;
	lodgingChgs = lodge1 * LODGE1_RATE * (NUM_DAYS - 1) + 
	              lodge2 * LODGE2_RATE * (NUM_DAYS - 1);
    totalChgs += lodgingChgs;

	// Calculate required deposit
	deposit = totalChgs * DEPOSIT_RATE;
	
	// Display Charges 
	cout << "\nNumber in party:  " << party; 
	cout << endl;
	cout << "Base charges:     $" << setw(8) << baseCharges << endl;
	cout << "Lodging:          $" << setw(8) << lodgingChgs << endl;
	cout << "Discount:         $" << setw(8) << discount << endl;
	cout << "Total Charges:    $" << setw(8) << totalChgs << endl;
	cout << "Required Deposit: $" << setw(8) << deposit << endl << endl;
	holdScreen();
}

/*************************************************
 *                   spelunk                     *
 * This function calculates the charges for the  *
 * Barron Cliff Spelunk package.                 *
 *************************************************/
void spelunk()
{
	const int NUM_DAYS = 8;  // Length of this trip
	int    party,			 // Number in party
		   tentsNeeded;	     // Number of tents being rented
	double baseCharges,	     // Base charge for the entire group
		   tentChgs,         // Total tent rental cost
 		   totalChgs,        // Total charges
		   discount = 0.0,	 // Discount amount
		   deposit;          // Required deposit

	cout << "\nBarron Cliff Spelunk Weekend\n";
	cout << "------------------------------------\n";
	cout << "How many will be going? ";
	cin  >> party;
	cout << "How many tents (sleep 4) do you want to rent? ";
	cin  >> tentsNeeded; 

	// Calculate base charges
	baseCharges = party * CAVE_RATE;
    totalChgs = baseCharges;

	// Calculate discount for 5 or more
	if (party > 4)
	{
		discount = (totalChgs * GROUP_DISCOUNT_RATE);
		totalChgs -= discount;
	}
	// Add cost of tent rental
	tentChgs = tentsNeeded * TENT_RATE * (NUM_DAYS - 1);
	totalChgs += tentChgs;

	// Calculate required deposit
	deposit = totalChgs * DEPOSIT_RATE;
	
	// Display Charges 
	cout << "\nNumber in party:  " << party; 
	cout << endl;
	cout << "Base charges:     $" << setw(8) << baseCharges << endl;
	cout << "Tent Rental:      $" << setw(8) << tentChgs << endl;
	cout << "Discount:         $" << setw(8) << discount << endl;
	cout << "Total Charges:    $" << setw(8) << totalChgs << endl;
	cout << "Required Deposit: $" << setw(8) << deposit << endl << endl;
	holdScreen();
}

/*************************************************
 *                 holdScreen                    *
 * This function holds the screen display until  *
 * the user is ready to return to the main menu. *
 *************************************************/	
void holdScreen()
{
 	cout << "Press Enter to return to the main menu. ";
	cin.ignore();
	cin.get();
	cout << "\n\n\n";
}
