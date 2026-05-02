#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a, b, c;
	double hypotenuse;

	cout << "Type the lengths: "; cin >> a >> b >> c;

	if ((a + b > c) && (a + c > b) && (b + c > a)) {
		if (a == b && b == c && a == c) {
			cout << "A equilateral triangle" << endl;
		}
		else if ((a == b && a != c && b != c) || (a == c && a != b && c != b) || (b == c && b != a && c != a)) {
			cout << "A isosceles triangle" << endl;
		}
		else if (pow(b, 2) + pow(c, 2) == pow(a, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(a, 2) + pow(b, 2) == pow(c, 2)) {
			if (a == b || a == c || b == c) {
				cout << "A isoceles right triangle" << endl;
			}
			else {
				cout << "A right triangle" << endl;
			}
		}
		else {
			cout << "A regular triangle" << endl;
		}
	}
	else {
		cout << "Not a triangle" << endl;
	}
}