// Assignment #5
// HACKER, MICHAEL
// A04868102
// CS1428-005
// ARRAYS

#include <iostream>
#include <fstream>
using namespace std;

int main () {

    char printNumbers [100];

    fstream numbers;
    numbers.open("numbers.txt");
    numbers >> printNumbers;

    for ( int i=0; i < 100; i++ ) {
        cout << printNumbers << endl;
        cin >> printNumbers[i];
    }

    return 0;
}
