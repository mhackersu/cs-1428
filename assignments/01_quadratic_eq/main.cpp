#include <iostream>
#include <cmath>
using namespace std;

int main() {

    float a, b, c, result1, result2, discrim;

    cout << "Welcome to the quadratic equation solver drive thru machine. Please enter the inputs."
            " Note: This machine does not currently support complex or imaginary roots." << endl;

    cout << "Enter the coefficient for a: " << endl;
    cin >> a;
    cout << "Enter the coefficient for b: " << endl;
    cin >> b;
    cout << "Enter the coefficient for c: " << endl;
    cin >> c;

    discrim = ( b*b ) - ( 4*a*c ); // Calculate the discriminant.

    if (discrim > 0 || discrim == 0) {
        result1 = (-b + sqrt(discrim)) / ( 2*a );
        result2 = (-b - sqrt(discrim)) / ( 2*a );
        cout << "The roots of x are: " << result1 << " , " << result2 << endl;
    }

    else {
        cout << "The roots are complex and are not supported by this machine." << endl;
    }

    return 0;
}