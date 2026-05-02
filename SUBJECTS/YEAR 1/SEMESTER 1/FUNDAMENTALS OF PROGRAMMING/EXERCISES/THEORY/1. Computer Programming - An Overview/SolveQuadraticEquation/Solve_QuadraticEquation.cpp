#include <iostream> // Add iostream library for I/O
#include <cmath> // Add cmath library to use sqrt()

using namespace std; // Specific the namespace std

int main() {
    double a, b, c; // Define double variables a, b and c

    // Ask the user to prompt a, b and c
    cout << "Type a (int), b (int) and c (int) on the same line with the separators are spaces: "; cin >> a >> b >> c;

    // Check if a is equal to 0
    if (a == 0) {
        // Print out "Using the Linear Equation Solver" when a is equal to 0
        cout << "Using the Linear Equation Solver" << endl;
    }
    else {
        // Define a double variable delta
        double delta = b*b - 4*a*c;

        // Check if one of these cases are true (delta < 0, delta = 0 and delta > 0)
        if (delta < 0) {
            // If delta is smaller than 0, then print "No solution"
            cout << "No solution" << endl;
        }
        else if (delta == 0) {
            // If delta = 0, then print out the calculation
            cout << "Answer: " << (-b)/(2*a) << endl;
        }
        else {
            // If delta > 0, then print out the calculations
            cout << "Answer: " << (-b + sqrt(float(delta)))/(2*a) << endl;
            cout << "Answer: " << float((-b - sqrt(float(delta)))/(2*a)) << endl;
        }
    }

    return 0;
}
