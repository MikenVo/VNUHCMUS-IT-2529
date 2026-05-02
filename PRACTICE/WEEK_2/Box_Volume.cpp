#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double a, b, c;

	while (true) {
		cin >> a >> b >> c;

		if (0 < a, b, c <= pow(10, 9)) {
			cout << fixed << setprecision(2);
			cout << a * b * c << endl;
			break;
		}
		else {
			continue;
		}
	}

	return 0;
}