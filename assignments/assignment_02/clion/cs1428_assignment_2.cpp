// Assignment #2
// HACKER, MICHAEL
// A04868102
// CS1428-005
// STARFLEET ACADEMY PROGRAM

#include <iostream>
using namespace std;

int main() {

    // Declare vars

    string firstName, raceName;
    int ageCount, satScore, raceType, satStat, ageStat, gpaStat, raceStat, acceptanceStat;
    double gpaIs;

    // Get user input

    cout << endl;
    cout << endl;

    cout << "Welcome to the Starfleet Academy Acceptance Qualification Program" << endl;
    cout << "Please enter your information according to the following prompts:" << endl;

    cout << "First Name: ";
    cin >> firstName;
    cout << "Age: ";
    cin >> ageCount;
    cout << "GPA: ";
    cin >> gpaIs;
    cout << "SAT Score: ";
    cin >> satScore;
    cout << "Select Race (Human, Vulcan, Klingon, Romulan): ";
    cin >> raceName;

    // Set raceType

    if ( raceName == "Human" ) {
        raceType = 0;
    } else if ( raceName == "Vulcan" ) {
        raceType = 1;
    } else if ( raceName == "Klingon" ) {
        raceType = 2;
    } else if ( raceName == "Romulan" ) {
        raceType = 3;
    }


    if (( gpaIs >= 3.5) && ( raceType != 3 ) && ( ageCount >= 17 )) {
        acceptanceStat = 1;
        cout << "GPA is 3.5 or greater, age is 17 or older. Non-Romulan" << endl;
        cout << "SAT exception: GPA of " << gpaIs << endl;
    } else if (( gpaIs >= 3.5 ) && ( raceType = 1 ) && ( ageCount >= 16 )) {
        acceptanceStat = 1;
        cout << "GPA is 3.5 or greater, age is 16 or older." << endl;
        cout << "Age exception: Vulcan." << endl;
    } else if (( satScore >= 1500 ) && ( gpaIs >= 3.5 ) && ( raceType != 3 )) {
        acceptanceStat = 1;
        cout << "SAT score is 1500 or greater, GPA is 3.5 or greater." << endl;
        cout << "Age exception: 1500+ SAT." << endl;
        cout << "Welcome young padawan." << endl;
    } else if ((( satScore < 1500 ) && ( satScore >= 1100 )) && (( raceType = 1 ) && ( ageCount >= 16 ))) {
        acceptanceStat = 1;
        cout << "Age is 16 or older, SAT is between 1100 and 1499" << endl;
        cout << "Age exception: Vulcan" << endl;
    } else if ((( satScore < 1500 ) && ( satScore >= 1100 )) && (( raceType != 3 ) && ( ageCount >= 17 ))) {
        acceptanceStat = 1;
        cout << "Non-Romulan, Age 17 or older, SAT is between 1100 and 1499" << endl;
        cout << "GPA exception: 1100+ SAT" << endl;
    } else if (( satScore < 1100 ) && ( satScore >= 800 ) && ( gpaIs >= 2.0 )
                 && ( raceType != 3 ) && ( raceType != 1 ) && ( ageCount >= 17 )) {
        acceptanceStat = 1;
        cout << "Non-Romulan, Age is 17 or older, SAT is between 800 and 1099." << endl;
        cout << "No exception status to report." << endl;
    }

    // Print acceptance

    if ( acceptanceStat == 0 ) {
        cout << "Your application status to SFA is: DENIED" << endl;
    } else if ( acceptanceStat == 1 ) {
        cout << "Congratulations, your application status to SFA is: APPROVED" << endl;
    }

    // Debug info

    // cout << endl;
    // cout << "Race Type: " << raceType << endl;
    // cout << "Acceptance Stat: " << acceptanceStat << endl;
    // cout << endl;

    return 0;
}
