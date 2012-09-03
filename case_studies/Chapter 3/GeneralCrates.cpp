// This program is used by General Crates, Inc. to calculate
// the volume, cost, customer charge, and profit of any crate
// to be built, when given its dimensions.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double length,   // crate length
	       width,    // crate width
	       height,   // crate height
	       volume,   // volume of the crate
	       cost,     // cost to build the crate
	       charge,   // customer charge for the crate
	       profit;   // profit made on the crate 

	cout << fixed << showpoint << setprecision(2);

	// Get crate dimensions
	cout << "Enter the dimensions of the crate (in feet):\n";
	cout << "Length: ";
	cin  >> length;
	cout << "Width: ";
	cin  >> width;
	cout << "Height: ";
	cin  >> height;

	// Perform calculations
	volume = length * width * height;
	cost = volume * 0.23;
	charge = volume * 0.5;
	profit = charge - cost;

   // Display calculated data
	cout << "The volume of the crate is ";
	cout << volume << " cubic feet.\n";
	cout << "Cost to build: $" << cost << endl;
	cout << "Charge to customer: $" << charge << endl;
	cout << "Profit: $" << profit << endl;
	return 0;
}
