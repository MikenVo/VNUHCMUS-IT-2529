/*
* Algorithm:
* 1. Define variables for coefficients
* 2. Let the user prompts the coefficients
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	// Quadratic equation form: "ax^2 + bx + c = d"

	float a, b, c, d; // Define variables for the coefficients

	cout << "Type a, b, c and d: "; cin >> a >> b >> c >> d; // Let the user prompts the coefficients
	
	c = c - d; // Change the form: "ax^2 + bx + (c-d) = 0"

	// Check if a is equal to 0 (1)
	if (a == 0) {
		// If (1) true, check if b is equal to 0 (2)
		if (b == 0) {
			// If (2) true, check if c is equal to 0 (3)
			if (c == 0) {
				// If (3) true, print out infinite solutions
				cout << "Infinite solutions" << endl;
			}
			else {
				// If (3) false, print out no solution
				cout << "No Solution" << endl;
			}
		}
		else {
			// If (2) false, check if c is equal to 0 (4)
			if (c == 0) {
				// If (4) true, print out infinite solutions
				cout << "Infinite solutions" << endl;
			}
			else {
				// If (4) false, print out (-c) / b as the solution
				cout << "Solution: " << (-c) / b << endl;
			}
		}
	}
	else {
		// If (1) false, define delta to calculate solutions
		float delta = b * b - 4 * a * c;

		// Check if delta is smaller than 0 (5)
		if (delta < 0) {
			// If (5) true, print out no solution
			cout << "No solution" << endl;
		}
		// If (5) false, check if delta is equal to 0 (6)
		else if (delta == 0) {
			// If (6) true, print out (-b) / (2 * a) as the solution
			cout << "Solution: " << (-b) / (2 * a) << endl;
		}
		else {
			// If (6) false, print out ((-b) + sqrt(delta)) / (2 * a) and ((-b) - sqrt(delta)) / (2 * a) as the solutions
			cout << "Solution: " << ((-b) + sqrt(delta)) / (2 * a) << endl;
			cout << "Solution: " << ((-b) - sqrt(delta)) / (2 * a) << endl;
		}
	}

	return 0;
}