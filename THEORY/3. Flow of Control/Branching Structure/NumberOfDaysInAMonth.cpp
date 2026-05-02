#include <iostream>

using namespace std;

int main() {
	int month, year;

	while (true) {
		cout << "Type a month and a year: "; cin >> month >> year;

		if (month >= 1 && year >= 0 && month <= 12) {
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
				if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
					cout << "31 days" << endl;
					break;
				}
				else if (month == 4 || month == 6 || month == 9 || month == 11) {
					cout << "30 days" << endl;
					break;
				}
				else {
					cout << "29 days" << endl;
					break;
				}
			}
			else {
				if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
					cout << "31 days" << endl;
					break;
				}
				else if (month == 4 || month == 6 || month == 9 || month == 11) {
					cout << "30 days" << endl;
					break;
				}
				else {
					cout << "28 days" << endl;
					break;
				}
			}
		}
		else {
			cout << "ERROR" << endl;
			continue;
		}
	}
}