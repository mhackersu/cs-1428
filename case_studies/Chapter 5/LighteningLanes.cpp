// This program computes average scores for 3 games of bowling 
// for each of 4 students. It displays this information in a file
// along with each student's name and previous average. 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	const int NUM_STUDENTS = 4,
	          NUM_GAMES = 3,
	          MAX_SCORE = 300;
			  
	ofstream report;       // output file stream object
	string teamName,       // the team name
	       name;           // a student's name           
	double oldAvg,         // a student's previous week's average
	       newAvg;         // a student's average for today's games      
	int    score,          // a student's score for 1 game
	       total;          // a student's total 3-game score

	// Open file and print headings
	report.open ("bowling.rpt");
	cout << "Enter your team name: ";
	getline(cin, teamName);
	report << "\n   Weekly Bowling Report for " << teamName << "\n\n";
	report << "Name          Last week's avg   Today's avg\n\n";
	report << fixed << showpoint << setprecision(1);

	// Get and process information for each student
	for (int student = 1; student <= NUM_STUDENTS; student++)
	{   total =  0;       // Reset the accumulator to 0 for each student
	    cout << "\nEnter your name: ";
	    getline(cin, name);  
	    cout << "Enter your last week's average game score: ";
	    cin  >> oldAvg;
	    while ((oldAvg < 0) || (oldAvg > MAX_SCORE))
	    {   cout << "Average must be between 0 and " << MAX_SCORE <<".\n"
	             << "Please reenter your last week's average: ";
	        cin  >> oldAvg;
	    }       
	    for (int game = 1; game <= NUM_GAMES; game++)
		{	cout << "Enter today's score for game " << game << ": ";

			cin  >> score;
			while ((score < 0) || (score > MAX_SCORE))
			{   cout << "Average must be between 0 and " << MAX_SCORE <<".\n"
			         << "Reenter score for game " << game << ": ";
				cin  >> score;
			}
			total += score;
		}
		newAvg = static_cast<double>(total) / NUM_GAMES;
		report << left << setw(12) << name << right
	           << setw(10) << oldAvg << setw(18) << newAvg << endl;
       
	    cin.ignore();      // Clear \n from input buffer
	}
	report.close();
	return 0;
}
