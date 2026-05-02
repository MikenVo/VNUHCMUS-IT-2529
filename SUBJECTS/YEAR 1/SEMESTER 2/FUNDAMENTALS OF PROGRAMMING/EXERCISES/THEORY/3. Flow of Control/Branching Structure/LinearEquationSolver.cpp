#include <iostream>

using namespace std;

int main() {
	// Linear equation form: ax + b = c
	float a, b, c; // Define a, b, c
	

	cout << "Type a, b and c: "; cin >> a >> b >> c; // Input a, b and c in the linear equation

	b = b - c; // To make the form "ax + b = 0"

	// Check if a is equal to 0 (1)
	if (a == 0) {
		// If (1) true, check if b is equal to 0 (2)
		if (b == 0) {
			// If (2) true, print out infinite solutions
			cout << "Infinite solutions" << endl;
		}
		else {
			// If (2) false, print out no solution
			cout << "No Solution" << endl;
		}
	}
	else {
		// If (1) false, check if b is equal to 0 (3)
		if (b == 0) {
			// If (3) true, print out infinite solutions
			cout << "Infinite solutions" << endl;
		}
		else {
			// If (3) false, print out (-b) / a
			cout << "Solution: " << (-b) / a << endl;
		}
	}

	return 0;
}