#include <iostream>

using namespace std;

int main()
{
    int NumStud;
    cout << "How many students: ";
    cin >> NumStud;

    int A = 0, B = 0, C = 0, D = 0, F = 0;
    int Total = 0, HighestScore = 0, LowestScore = 100;
    string Name;
    int Score;
    char Grade;

    for (int StudNum = 1; StudNum <= NumStud; StudNum++)
    {
        cout << "Student #" << StudNum << "'s name: ";
        cin >> Name;
        cout << Name << "'s score: ";
        cin >> Score;
        while (Score < 0 || Score > 100)
        {
            cout << Name << "'s score: ";
            cin >> Score;
        }
        if (Score >= 90)
            Grade = 'A';
        else
            if (Score >= 80)
                Grade = 'B';
            else
                if (Score >= 70)
                    Grade = 'C';
                else
                    if (Score >= 60)
                        Grade = 'D';
                    else
                        Grade = 'F';
        cout << Name << " get's a grade of " << Grade << endl;
        if (Grade == 'A')
            A += 1;
        else
            if (Grade == 'B')
                B += 1;
            else
                if (Grade == 'C')
                    C += 1;
                else
                    if (Grade == 'D')
                        D += 1;
                    else
                        F += 1;
        if (Score < LowestScore)
            LowestScore = Score;
        if (Score > HighestScore)
            HighestScore = Score;
        Total += Score;
    }

    cout << endl;
    cout << "The highest score was " << HighestScore << endl;
    cout << "The lowest  score was " << LowestScore << endl;
    cout << "The average score was "
         << Total/static_cast<double>(NumStud) << endl;
    cout << "Number of A's: " << A << endl;
    cout << "Number of B's: " << B << endl;
    cout << "Number of C's: " << C << endl;
    cout << "Number of D's: " << D << endl;
    cout << "Number of F's: " << F << endl;

    return 0;
}
