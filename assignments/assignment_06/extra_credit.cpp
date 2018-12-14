// Assignment #6
// HACKER, MICHAEL
// A04868102
// CS1428-005
// EXTRA CREDIT

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void inputCountAndCompareArray (ifstream &, const int, string[], int &, string &);
// void readWordsFileAndCompare (ifstream &, const int, string[]);

int main () {

    const int SIZE = 100;
    string arrayObject [SIZE];
    int arrayCount;
    string wordFile [SIZE];
    string singleWord = "happy";

    ifstream fin;
    fin.open("input.txt");

    if(!fin) {
        cout << "Error reading file." << endl;
        return 1;
    }

    inputCountAndCompareArray(fin, SIZE, arrayObject, arrayCount, singleWord);

    fin.close();
    // fin.open("words.txt");
    //
    // if(!fin) {
    //     cout << "Error reading file." << endl;
    //     return 1;
    // }
    //
    // readWordsFileAndCompare(fin, SIZE, wordFile);
    //
    // fin.close();

    return 0;
}

void inputCountAndCompareArray (ifstream & fin, const int SIZE, string arrayObject[], int & arrayCount, string & singleWord) {

    arrayCount = 0;
    int trackingWordCounts [SIZE];

    while ( fin >> arrayObject[arrayCount] && arrayCount < SIZE )
        arrayCount++;
        cout << "the arrayCount is " << arrayCount << endl;

    // print out arrays
    cout << "arrayObject is:" << endl;
    cout << "--------------------" << endl;

    for(int i=0; i<arrayCount; i++) {

        cout << "The index position is " << i << " and the object is ";
        cout << setw(8) << left << arrayObject[i] << endl;
        cout << "tracking word counts is " << trackingWordCounts[i] << endl;

        if ( arrayObject[i] == singleWord ) {
            cout << "the object " << arrayObject[i] << " matches the singleWord." << " and the index position is " << i << endl;
            trackingWordCounts[i] += 1;
        } else
            trackingWordCounts[i] = -1;
            cout << "the object " << arrayObject[i] << " does not match the singleWord. " << "-1" << endl;
    }
}

// void readWordsFileAndCompare (ifstream & fin, const int SIZE, string wordFile[]);
