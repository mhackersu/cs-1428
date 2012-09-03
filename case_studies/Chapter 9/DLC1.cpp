 // Demetris Leadership Center (DLC) Product Lookup Program
 // This program manages an array of product structures.     
 // It allows the user to enter a product number, then finds 
 // and displays information on that product. 
 #include <iostream>
 #include <string>
 using namespace std;
 
 struct ProdStruct
 {
	 int    id;               // Product number
	 string title,            // Product title
		    description;      // Product description
	 double price;            // Product unit price
	 int    sold;             // Units sold during the past 6 months

	 // Default constructor for a ProdStruct structure
	 ProdStruct()
	 {	 price = id = sold = 0;
		 title = description = "";
	 }
	 // Constructor to set initial data values
	 ProdStruct(int i, string t, string d, double p, int s)
	 {	 id = i;
		 title = t;
		 description = d;
		 price = p;
		 sold = s;
	 }
 };
 
 // Function prototypes
 int getProdNum(int, int);
 int binarySearch(ProdStruct [], int, int);
 void displayProd(ProdStruct [], int);
 
 int main()
 {
    const int NUM_PRODS = 9,        // Number of products carried by DLC
              MIN_PROD_NUM = 914,   // Lowest product number
              MAX_PROD_NUM = 922;   // Highest product number
 
    // Create and initialize the array of ProdStruct structures  
    ProdStruct product[NUM_PRODS] =     
    { 
		ProdStruct(914, "Six Steps to Leadership",  "Book",     12.95, 842),
		ProdStruct(915, "Six Steps to Leadership",  "Audio CD", 14.95, 416),
		ProdStruct(916, "The Road to Excellence",   "DVD",      18.95, 127),
		ProdStruct(917, "Seven Lessons of Quality", "Book",     16.95, 514),
		ProdStruct(918, "Seven Lessons of Quality", "Audio CD", 21.95, 437),
		ProdStruct(919, "Seven Lessons of Quality", "DVD",      31.95, 269),
		ProdStruct(920, "Teams are Made, Not Born", "Book",     14.95,  97),
		ProdStruct(921, "Leadership for the Future","Book",     14.95, 492),
		ProdStruct(922, "Leadership for the Future","Audio CD", 16.95, 212)
    };
 
    int prodNum,     // Product number the user wants
        index;       // Array subscript where the record is found
    char again;      // Does user want to look up another record (y/n)?
 
    do
    {   // Get the desired product number
		prodNum = getProdNum(MIN_PROD_NUM, MAX_PROD_NUM);

		// Find the array index of the record for that product
		index = binarySearch(product, NUM_PRODS, prodNum);

		if (index == -1)
			cout << "That product number was not found.\n";
		else
			displayProd(product, index);

		cout << "\nWould you like to look up another product? (y/n) ";
		cin  >> again;
	} while (again == 'y' || again == 'Y');
    return 0;
 }
 
/*************************************************************
 *                          getProdNum                       *
 * Passed in: legal minimum and maximum product numbers      *
 * Returned : a valid product number                         *
 *                                                           *
 * The getProdNum function accepts, validates, and returns   *
 * a product number input by the user.                       *
 *************************************************************/
 int getProdNum(int min, int max)
 {
    int prodNum;
 
    // Input the desired product number
    cout << "Enter the item's product number "
         << min << " - " << max << ": ";
    cin  >> prodNum;
 
    // Validate input
    while (prodNum < min || prodNum > max)
    {	cout << "Invalid product number.\n"
	         << "Enter the item's product number "
			 << min << " - " << max << ": ";
	    cin  >> prodNum;
	}
    return prodNum;
 }
 
/****************************************************************
 *                          binarySearch                        *
 * Passed in: the product array, its size, and the product      *
 *            ID being searched for                             *
 * Returned : the array index for the record with that ID       *
 *                                                              *
 * This function is modified to do a binary search on the id    *
 * field of an array of ProdStruct structures, looking for a    *
 * record (i.e., an array element) whose id member matches      *
 * value, which holds the product id passed to the function.    *
 * If the record is found, its array subscript is returned.     *
 * If it is not found , -1 is returned.                         *
 ****************************************************************/
 int binarySearch(ProdStruct array[], int size, int value)
 {
    int  first = 0,                     // First array element
         last = size - 1,               // Last array element
         middle,                        // Midpoint of search
         position = -1;                 // Position of search value
    bool found = false;                 // Flag
 
    while (!found && first <= last)
    {
		middle = (first + last) / 2;    // Calculate midpoint
		if (array[middle].id == value)  // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle].id > value) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;            // If value is in upper half
	}
    return position;
 }
 
/******************************************************************
 *                            displayProd                         *
 * Passed in: the product array and the index of a specific       *
 *            element of that array                               *
 *                                                                *
 * This function displays 4 fields (i.e., structure members) of   *
 * the array element whose index is passed to the function.       *
 ******************************************************************/
 void displayProd(ProdStruct product[], int index)
 {
    cout << "\nID:          "  << product[index].id;
    cout << "\nTitle:       "  << product[index].title;
    cout << "\nDescription: "  << product[index].description;
    cout << "\nPrice:       $" << product[index].price << endl;
 }
