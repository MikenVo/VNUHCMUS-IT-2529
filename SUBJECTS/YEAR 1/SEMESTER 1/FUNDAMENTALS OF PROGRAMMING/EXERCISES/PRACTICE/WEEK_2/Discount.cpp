#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double percent, quota;

	while (true) {
		cin >> percent >> quota;
		
		if (0 < percent, quota <= pow(10, 9)) {
			double purchase = (quota * 100) / percent;

			cout << fixed << setprecision(2);
			cout << purchase << endl;
			break;
		}
		else {
			continue;
		}
	}

	return 0;
}