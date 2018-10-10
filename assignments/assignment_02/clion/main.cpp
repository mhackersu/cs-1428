// Assignment #2
// HACKER, MICHAEL
// CS1428-005
// STARFLEET ACADEMY PROGRAM

#include <iostream>
using namespace std;

int main() {

    string firstName, raceName;
    int AGE, SAT, raceType, satStat, ageStat, gpaStat, raceStat;
    double GPA;


    cout << "First Name: ";
    cin >> firstName;
    cout << "Age: ";
    cin >> AGE;
    cout << "GPA: ";
    cin >> GPA;
    cout << "SAT Score: ";
    cin >> SAT;
    cout << "Select Race (Human, Vulcan, Klingon, Romulan): ";
    cin >> raceName;

    if ( raceName == "Human" ) {
        raceType = 0;
    } else if ( raceName == "Vulcan" ) {
        raceType = 1;
    } else if ( raceName == "Klingon" ) {
        raceType = 2;
    } else if ( raceName == "Romulan" ) {
        raceType = 3;
    }

    if (( AGE >= 16 ) && ( raceType = 1 )) {
        ageStat = 1;
    } else if (( AGE >= 17 ) && ( raceType = 1 )) {
        ageStat = 1;
    } ageStat = 0;

    if ( GPA >= 3.5 ) {
        gpaStat = 1;
        satStat = 1;
    } else if ( GPA < 3.5 ) {
        satStat = 0;
        gpaStat = 1;
    } else if (GPA >= 2.0 ) {
        gpaStat = 1;
    } gpaStat = 0;

    if ( SAT > 1500 ) {
        satStat = 1;
        ageStat = 1;
    } else if ( SAT >= 1500 ) {
        satStat = 1;
    } else if ( SAT >= 1100 ) {
        satStat = 1;
    } else if ( SAT >= 800 ) {
        satStat = 1;
    }
    // satStat = 0;

    if ( raceName != "Romulan" ) {
        raceStat = 1;
    } else if ( raceName == "Romulan" ) {
        raceStat = 0;
    }

    if ( satStat == '1' ) {
        cout << "SAT Stat is True\n";
    } else if ( satStat == '0' ) {
        cout << "SAT Stat is False\n";
    }

    cout << "Name: " << firstName << endl;
    cout << "Race Name: " << raceName << endl;
    cout << "Race Type: " << raceType << endl;
    cout << "Age Stat: " << ageStat << endl;
    cout << "GPA Stat: " << gpaStat << endl;
    cout << "SAT Stat: " << satStat << endl;
    cout << "Race Stat: " << raceStat << endl;


    return 0;
}
