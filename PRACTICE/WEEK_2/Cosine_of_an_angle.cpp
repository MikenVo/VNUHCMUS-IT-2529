#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double num;

	while (true) {
		if (pow(-10, 9) <= num <= pow(10, 9)) {
			cin >> num;
			
			const double pi = acos(-1);
			num = num * pi / 180;

			cout << fixed << setprecision(2);
			cout << cos(num) << endl;
			break;
		}
		else {
			continue;
		}
	}

	return 0;
}