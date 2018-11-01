// Assignment #4
// HACKER, MICHAEL
// A04868102
// CS1428-005
// PRIME NUMBERS REVISITED

#include <iostream>
using namespace std;

bool Prime (int num);

int num;

int main() {

    // Set vars.
    // string primeResult;
    bool isPrime = 1;
    int checkIfPrime = 0;

    // Request user input.
    cout << "Enter a positive integer to be evauated: " << endl;
    cin >> checkIfPrime;

    // Validate user input.
    while ( checkIfPrime < 1 ) {
        cout << "Integer is not positive. Please enter a positive integer." << endl;
        cin >> checkIfPrime;
    }

    // Debug
    Prime(num);

    // Print prime state.
    if ( isPrime == 1 ) {
        cout << "The number " << checkIfPrime << " is prime." << endl;
    } else cout << "The number " << checkIfPrime << " is not prime." << endl;

    return 0;
}

bool Prime (int num) {

    int i, j = 0;

    // Calculate if prime.
    for ( i = 2; i < num; i++ ) {
        if (( num % i ) == 0 ) {
            j++;
            break;
        }
    }
    return num;
}
