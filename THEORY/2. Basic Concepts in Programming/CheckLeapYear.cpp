#include <iostream>

using namespace std;

int main() {
	int year;

	while (true) {
		cout << "Type a year (from 0 to inf): "; cin >> year;

		if (year >= 0) {
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
				cout << "A leap year!" << endl;
				break;
			}
			else {
				cout << "Not a leap year!" << endl;
				break;
			}
		}
		else {
			cout << "ERROR" << endl;
			continue;
		}
	}

	return 0;
}