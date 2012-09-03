// This program is used by Crazy Al's Computer Emporium
// to calculate the monthly pay of commissioned salespeople.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double sales,         // Monthly sales
	       rate,          // Commission rate
		   commission,    // Commission amount
		   advance,       // Advanced pay drawn
		   remainingPay;  // Amount of commission remaining to be paid

	// Get salesperson's sales and amount of advanced pay
	cout << "Enter the salesperson's monthly sales: ";
	cin  >> sales;
	cout << "Enter the amount of advanced pay for this ";
	cout << "salesperson: ";
	cin  >> advance;

	// Determine the commission rate
	if (sales < 10000)
		rate = 0.05;
	else if (sales < 14999)
		rate = 0.1;
	else if (sales < 17999)
		rate = 0.12;
	else if (sales < 21999)
		rate = 0.14;
	else
		rate = 0.16;

	// Calculate sales commission and remaining pay
	commission = sales * rate;
	remainingPay = commission - advance;

	// Display the results
	cout << fixed << showpoint << setprecision(2);
	cout << "\nPay Results\n";
	cout << "-----------\n";
	cout << "Sales:          $" << setw(8) << sales << endl;
	cout << "Commission Rate: " << setw(8) << rate  << endl;
	cout << "Commission:     $" << setw(8) << commission << endl;
	cout << "Advanced Pay:   $" << setw(8) << advance << endl;
	cout << "Remaining Pay:  $" << setw(8) << remainingPay << endl;

	return 0;
}
