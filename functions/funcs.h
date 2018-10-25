#include <iostream>
using namespace std;

bool EligibleForHonors(double GPA, int HoursCompleted)
{
    return ((HoursCompleted >= 12) && (GPA >= 3.5));
}

string Honors(double GPA, int HoursCompleted)
{
    if (HoursCompleted < 12) return "";
    if (GPA == 4.0) return "President's Honor Roll";
    if (GPA >= 3.75) return "Scholastic Excellence Roll";
    if (GPA >= 3.75) return "Scholastic Leadership Roll";
    return "";
}
double DollarsToEuros(double Dollars)
{
    return Dollars * 0.718545664;
}

double EurosToDollars(double Euros)
{
    return Euros / 0.718545664;
}

double MetricDistance(int Feet, int Inches)
{
    return (Feet * 12 + Inches) * 0.0254;
}

double GrossPay(double Hours, double Rate, bool EligibleForOvertime)
{
    if ((Hours <= 40) || (!EligibleForOvertime)) return Hours * Rate;
    return ((Hours - 40) * Rate * 1.5) + (Rate * 40);
}

void AsteriskLines(int Count)
{
    while (Count > 0)
    {
        cout << "**************************************************\n";
        Count--;
    }
}

void Raise(double& Salary,double Percent)
{
    Salary *= (1+Percent/100);
}
