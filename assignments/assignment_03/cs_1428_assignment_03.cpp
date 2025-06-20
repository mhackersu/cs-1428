// Assignment #3
// HACKER, MICHAEL
// A04868102
// CS1428-005
// WIZ-BANG PRIME NUMBER THING

#include <iostream>
using namespace std;

int main() {

    // Set vars.
    bool isPrime;
    int checkIfPrime = 0, i = 2, j = 0;

    // Request user input.
    cout << "Enter a positive integer to be evauated: " << endl;
    cin >> checkIfPrime;

    // Validate user input.
    while ( checkIfPrime < 1 ) {
        cout << "Integer is not positive. Please enter a positive integer." << endl;
        cin >> checkIfPrime;
    }

    // Calculate if prime.
    for ( i = 2; i < checkIfPrime; i++ ) {
        if (( checkIfPrime % i ) == 0 ) {
            j++;
            break;
        }
    // Declare prime state.
    } if ( j == 0 ) {
        isPrime = 1;
    } else isPrime = 0;

    // Print prime state.
    if ( isPrime == 1 ) {
        cout << "The number " << checkIfPrime << " is prime." << endl;
    } else cout << "The number " << checkIfPrime << " is not prime." << endl;

    return 0;
}
