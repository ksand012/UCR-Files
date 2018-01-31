#include <iostream>
using namespace std;

// Global const values for intersect return value
const int OK = 0;
const int DIV_ZERO = 1;

// FIXME Add intersect function here

int main() {
    // line 1: y = a1*x + b1
    // line 2: y = a2*x + b2
    // lines intersect at xi, yi

    double a1 = 0.0, b1 = 0.0, a2 = 0.0, b2 = 0.0;
    cout << "Enter coefficients for Line 1 (a1, b1): ";
    cin >> a1 >> b1;
    cout << endl;

    cout << "Enter coefficients for Line 2 (a2, b2): ";
    cin >> a2 >> b2;
    cout << endl;

    cout << "Line 1: Y = " << a1 << "X + " << b1 << endl;
    cout << "Line 2: Y = " << a2 << "X + " << b2 << endl;

    double xi, yi;

    // FIXME: call (invoke) intersect function here

    if (flag == DIV_ZERO) {
        cout << "Lines are parallel" << endl;
    }
    else {
        cout << endl << "Lines 1 & 2 intersect at {" << xi << ", " << yi << '}' << endl;

        cout << "Proof: yi on Line 1 at (xi = " << xi << ") is "
            << a1 * xi + b1 << endl;
        cout << "       yi on Line 2 at (xi = " << xi << ") is "
            << a2 * xi + b2 << endl;
    }

    return 0;
}