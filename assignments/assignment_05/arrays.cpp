// NAME: HACKER, MICHAEL
// COURSE: CS1428
// ASSIGNMENT_5 - ARRAYS
// A04868120

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void inputAndCountArray (ifstream &, const int, double[], int &);
int sumArray (double[], const int);
double avgArray (int, int);

int main () {

    const int MAXSIZE = 100;
    double arrayObject [MAXSIZE];
    int arrayCount;
    int arraySum;
    double arrayAvg;

    ifstream fin;
    fin.open("input.txt");

    if(!fin) {
        cout << "Error. File not found." << endl;
        return 1;
    }

    inputAndCountArray (fin, MAXSIZE, arrayObject, arrayCount);

    cout << "arrayItems is " << arrayCount << endl;

    // Print items in array
    cout << "Items in array: " << endl;
    for ( int i=0; i<arrayCount; i++ ) {
        cout << setw(8) << left << arrayObject[i] << '\t' << endl;
    }

    arraySum = sumArray(arrayObject, MAXSIZE);

    cout << "arraySum is " << arraySum << endl;

    arrayAvg = avgArray(arraySum, arrayCount);

    cout << "The average of all elements in the array is: " << arrayAvg << endl;

    fin.close();

    return 0;
}

void inputAndCountArray (ifstream & fin, const int SIZE, double AI[], int & count) {
    count = 0;

    while ( fin >> AI[count] && count < SIZE )
        count++;
}

int sumArray(double A[], const int SIZE) {
    int total = 0;

    for (int i=0; i<SIZE; i++) {
        total += A[i];
    }

    return total;
}

double avgArray(int arraySum, int arrayCount) {
    int avg = 0;

    avg = arraySum / arrayCount;

    return avg;
}
