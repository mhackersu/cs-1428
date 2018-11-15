// Assignment #4
// HACKER, MICHAEL
// A04868102
// CS1428-005
// PRIME NUMBERS REVISITED

#include <iostream>
using namespace std;

bool Prime (int checkIfPrime);

int checkIfPrime;

int main() {

    // Set vars.
    int checkIfPrimeLower = 0;
    int checkIfPrimeUpper = 0;

    // Validate and gather user input.
    while ( ( checkIfPrimeLower < 1 ) || ( checkIfPrimeUpper < 1 ) ) {
        cout << "Integer is not positive. Please enter positive integers." << endl;
        cout << "Enter a positive integer for the lower limit to be evauated: " << endl;
        cin >> checkIfPrimeLower;
        cout << "Enter a positive integer for the upper limit to be evauated: " << endl;
        cin >> checkIfPrimeUpper;
    }

    // Call prime function
    cout << "The prime numbers from " << checkIfPrimeLower << " to " << checkIfPrimeUpper << " are:" << endl;
    for (  int iPrime = checkIfPrimeLower; iPrime < checkIfPrimeUpper; iPrime++ ) {
        checkIfPrime = iPrime;
        Prime(checkIfPrime);
        if (( Prime(checkIfPrime)) == 1 ) {
            cout << iPrime << endl;
        }
    } cout << "Thank you, drive thru." << endl;

    // Debug
    // cout << Prime(checkIfPrime) << endl;

    return 0;
}

bool Prime (int checkIfPrime) {

    int i, j = 0;

    // Calculate if prime.
    for ( i = 2; i < checkIfPrime; i++ ) {
        if (( checkIfPrime % i ) == 0 ) {
            j++;
            break;
        }
    }

    // Declare prime state.
    if ( j == 0 ) {
        return 1;
    } else return 0;

}
