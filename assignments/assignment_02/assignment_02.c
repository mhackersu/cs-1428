// Assignment #2
// HACKER, MICHAEL
// CS1428-005
// STARFLEET ACADEMY PROGRAM

#include <iostream> 
#include <string>
using namespace std;

main() {

    string firstName, race;
    int AGE, SAT, raceType;
    double GPA;
    bool satStat, ageStat, gpaStat, raceStat; 

    cout << "First Name: ";
    cin >> firstName;
    cout << "Age: ";
    cin >> AGE;
    cout << "GPA: ";
    cin >> GPA;
    cout << "SAT Score: ";
    cin >> SAT;
    cout << "Select Race (Human, Vulcan, Klingon, Romulan): ";
    cin >> race;

    if ( race = "Human" ) { 
        raceType = 0;
    } else if ( race = "Vulcan" ) { 
        raceType = 1;
    } else if ( race = "Klingon" ) { 
        raceType = 2;
    } else if ( race = "Romulan" ) { 
        raceType = 3;
    }

    if (( AGE >= 16 ) && ( raceType = 1 )) { 
        ageStat = "True";
    } else if (( AGE >= 17 ) && ( raceType = 1 )) { 
        ageStat = "True";
    } ageStat = "False";

    if ( GPA >= 3.5 ) {
        gpaStat = "True";
        satStat = "True";
    } else if ( GPA < 3.5 ) { 
        satStat = "False";
        gpaStat = "True";
    } else if (GPA >= 2.0 ) {
        gpaStat = "True";
    } gpaStat = "False";

    if ( SAT > 1500 ) { 
        satStat = "True";
        ageStat = "True";
        } else if ( SAT >= 1500 ) {
            satStat = "True";
            } else if ( SAT >= 1100 ) {
                satStat = "True"; 
                } else if ( SAT >= 800 ) {
                    satStat = "True"; 
                    } 
    satStat = "False";

    if ( race != "Romulan" ) { 
        raceStat = "True";
    } else if ( race == "Romulan" ) { 
        raceStat = "False"; 
    } 

    if ( satStat = "True" ) { 
        cout << "SAT Stat is True\n";
    } else if ( satStat = "False" ) { 
        cout << "SAT Stat is False\n";
    }
 
cout << "Age Stat: " << ageStat << "\n" << "GPA Stat: " << gpaStat << "\n";
cout << "SAT Stat: " << satStat << "\n";


    return 0;
}
