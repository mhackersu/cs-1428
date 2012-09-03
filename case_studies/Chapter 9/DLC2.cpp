// This program produces a sales report for the Demetris
// Leadership Center. It uses an array of structures.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct ProdStruct
{
	int    id;                 // Product number
	string title,              // Product title
		   description;        // Product description
	double price;              // Product unit price
	int    sold;               // Units sold during the past 6 months

    // Default constructor for a ProdStruct structure
	ProdStruct()
	{   price = id = sold = 0;
		title = description = "";
	}
	
	// Constructor to set initial data values
	ProdStruct(int i, string t, string d, double p, int s)
	{   id = i;
		title = t;
		description = d;
		price = p;
		sold = s;
	}
};

struct SalesStruct
{
	int    id;                // Product number 
	double dollarAmt;         // Dollar amount of sales in past 6 months
};

// Function prototypes
void calcSales(ProdStruct[], SalesStruct [], int);
void sortBySales(SalesStruct [], int);
void showOrder(SalesStruct [], int);
void showTotals(ProdStruct[], SalesStruct [], int);

int main()
{
	const int NUM_PRODS = 9;    // Number of products carried
	ProdStruct product[NUM_PRODS] =  
	{
		ProdStruct(914, "Six Steps to Leadership",  "Book",     12.95,  842),
		ProdStruct(915, "Six Steps to Leadership",  "Audio CD", 14.95,  416),
		ProdStruct(916, "The Road to Excellence",   "DVD",      18.95,  127),
		ProdStruct(917, "Seven Lessons of Quality", "Book",     16.95,  514),
		ProdStruct(918, "Seven Lessons of Quality", "Audio CD", 21.95,  437),
		ProdStruct(919, "Seven Lessons of Quality", "DVD",      31.95,  269),
		ProdStruct(920, "Teams are Made, Not Born", "Book",     14.95,   97),
		ProdStruct(921, "Leadership for the Future","Book",     14.95,  492),
		ProdStruct(922, "Leadership for the Future","Audio CD", 16.95,  212)
	};
	SalesStruct sales[NUM_PRODS];

	calcSales(product, sales, NUM_PRODS);
	sortBySales(sales, NUM_PRODS);
	cout << fixed << showpoint << setprecision(2);
	showOrder(sales, NUM_PRODS);
	showTotals(product, sales, NUM_PRODS);
	return 0;
}

/*************************************************************
 *                       calcSales                           *
 * Passed in: the product array, the sales array, and the    *
 *            size of the arrays                             *
 *                                                           *
 * This function uses data in the product array to get the   *
 * product id and to calculate the product dollarAmt to be   *
 * stored for each product in the sales array.               *
 *************************************************************/
void calcSales(ProdStruct product[], SalesStruct sales[], int numProds)
{
	for (int index = 0; index < numProds; index++)
	{   sales[index].id = product[index].id;
	    sales[index].dollarAmt = product[index].price * product[index].sold;
	}
}

/*************************************************************
 *                         sortBySales                       *
 * Passed in: the sales array and its size                   *
 *                                                           *
 * This function performs a selection sort, arranging array  *
 * elements in descending-order based on the value of the    *
 * dollarAmt structure member.                               *
 *************************************************************/
void sortBySales(SalesStruct sales[], int size)
{
	int startScan, maxIndex;
	SalesStruct maxValue;   // Holds structure with largest dollarAmt so far

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		maxIndex = startScan;
		maxValue = sales[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (sales[index].dollarAmt > maxValue.dollarAmt)
			{
				maxValue = sales[index];
				maxIndex = index;
			}
		}
		sales[maxIndex] = sales[startScan];
		sales[startScan] = maxValue;
	}
}

/**************************************************************
 *                        showOrder                           *
 * Passed in: the sales array and its size                    *
 *                                                            *
 * This function displays the product number and dollar sales *
 * amount of each product DLC sells.                          *
 **************************************************************/
void showOrder(SalesStruct sales[], int numProds)
{
	cout << "Product ID \t  Sales\n";
	cout << "----------------------------\n";
	for (int index = 0; index < numProds; index++)
	{
		cout << sales[index].id << "\t\t  $";
		cout << setw(8) << sales[index].dollarAmt << endl;
	}
	cout << endl;
}

/*************************************************************
 *                        showTotals                         *
 * Passed in: the product array, the sales array, and the    *
 *            size of the arrays                             *
 *                                                           *
 * This function calculates and displays the total quantity  *
 * of items sold and the total dollar amount of sales.       *
 *************************************************************/
void showTotals(ProdStruct product[], SalesStruct sales[], int numProds)
{
	int totalUnits = 0;
	double totalSales = 0.0;

	for (int index = 0; index < numProds; index++)
	{
		totalUnits += product[index].sold;
		totalSales += sales[index].dollarAmt;
	}
	cout << "Total units Sold:  " << totalUnits << endl;
	cout << "Total sales:      $" << totalSales << endl;
}
