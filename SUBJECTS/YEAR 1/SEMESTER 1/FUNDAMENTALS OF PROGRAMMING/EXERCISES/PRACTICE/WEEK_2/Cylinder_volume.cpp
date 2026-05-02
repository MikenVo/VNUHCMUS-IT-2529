#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	double radius, height;
	const double pi = 3.14;

	while (true) {
		cin >> radius >> height;

		if (pow(-10, 9) <= radius, height <= pow(10, 9)) {
			double volume = pi * radius * radius * height;
			cout << fixed << setprecision(2) << volume << endl;
			break;
		}
		else {
			continue;
		}
	}
		
	return 0;
}