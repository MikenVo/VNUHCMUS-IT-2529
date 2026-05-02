#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");

	if (input && output) {
		double a, b, c, d; // First use as a variable for d in ax^2 + bx + c = d, later use as a variable for delta
		input >> a >> b >> c >> d;

		c -= d;
		if (a == 0) {
			// bx + c = 0
			if (b == 0) {
				// c = 0
				if (c == 0) {
					output << "Infinite solutions" << endl;
				}
				else {
					output << "No solutions" << endl;
				}
			}
			else {
				// bx + c = 0
				output << "Solution: " << -c / b << endl;
			}
		}
		else {
			// ax^2 + bx + c = 0
			d = pow(b, 2) - 4 * a * c;
			if (d < 0) {
				output << "No solutions" << endl;
			}
			else if (d == 0) {
				output << "Solution: " << -b / (2 * a) << endl;
			}
			else {
				output << "Solution 1: " << (-b + sqrt(d)) / (2 * a) << endl;
				output << "Solution 2: " << (-b - sqrt(d)) / (2 * a) << endl;
			}
		}
	}
	else {
		cout << "ERROR" << endl;
		return 1;
	}

	input.close();
	output.close();
	return 0;
}