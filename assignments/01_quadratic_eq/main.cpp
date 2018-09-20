#include <iostream>
#include <cmath>
using namespace std;

int main() {

    float a, b, c, d, d1, d2, result1, result2;

    cout << "Welcome to the quadratic equation calculator. Please enter the inputs." << endl;
    cout << "Note: This machine does not support complex or imaginary roots." << endl;

    cout << "Enter the coefficient for a: " << endl;
    cin >> a;
    cout << "Enter the coefficient for b: " << endl;
    cin >> b;
    cout << "Enter the coefficient for c: " << endl;
    cin >> c;

    // Calculate the discriminant using the pow function.
    d = (( pow (b, 2) ) - ( 4*a*c ));

    // Calculate the roots using the pow function.
    d1 = (-b + ( pow ( d, (1/2) )));
    d2 = (+b + ( pow ( d, (1/2) )));

    if (d > 0 || d == 0) {
        result1 = d1 / ( 2*a );
        result2 = d2 / ( 2*a );
        cout << "The roots of x are: " << result1 << " , " << result2 << endl;
    } else {
        cout << "The roots are complex and or imaginary and are not supported by this calculator." << endl;
    }

    // Testing outputs

    // cout << "Testing outputs: " << endl;
    // cout << "The output of d is: " << d << endl;
    // cout << "The output of d1 is: " << d1 << endl;
    // cout << "The output of d2 is: " << d2 << endl;

    return 0;
}