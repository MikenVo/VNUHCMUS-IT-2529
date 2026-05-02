#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	double km, hour, minute, second;

	while (true) {
		cin >> km >> hour >> minute >> second;

		if (0 < km, hour, minute, second <= pow(10, 9)) {
			double pace = (hour * 60 + minute + second / 60) / km;
			double speed = km / (hour + minute / 60 + second / 3600);

			cout << fixed << setprecision(2) << pace << " " << speed << endl;
			break;
		}
		else {
			continue;
		}
	}
}