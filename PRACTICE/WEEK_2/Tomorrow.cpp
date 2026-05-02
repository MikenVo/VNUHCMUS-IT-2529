#include <iostream>

using namespace std;

int main() {
	int day, month, year;

	cout << "Type day, month and year: "; cin >> day >> month >> year;

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (1 <= day && day < 30 && 1 <= month && month <= 12) {
				cout << day + 1 << " " << month << " " << year << endl;
			}
			else if (day == 31 && month == 12) {
				cout << 1 << " " << 1 << " " << year + 1 << endl;
			}
			else {
				cout << "Invalid date" << endl;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (1 <= day && day < 30 && 1 <= month && month <= 11) {
				cout << day + 1 << " " << month << " " << year << endl;
			}
			else if (day == 30) {
				cout << 1 << " " << 1 << " " << year<< endl;
			}
			else {
				cout << "Invalid date" << endl;
			}
		}
		else if (month == 2) {
			if (day == 29) {
				cout << 1 << " " << 1 << " " << year + 1 << endl;
			}
			else if (day < 29) {
				cout << day + 1 << " " << month << " " << year << endl;
			}
			else {
				cout << "Invalid date" << endl;
			}
		}
	}
	else {
		if (day == 29 && month == 2) {
			cout << "Invalid date" << endl;
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (1 <= day && day < 30 && 1 <= month && month <= 10) {
				cout << day + 1 << " " << month << " " << year << endl;
			}
			else if (day == 31 && month == 12) {
				cout << 1 << " " << 1 << " " << year + 1 << endl;
			}
			else {
				cout << "Invalid date" << endl;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (1 <= day && day < 30 && 1 <= month && month <= 11) {
				cout << day + 1 << " " << month << " " << year << endl;
			}
			else if (day == 30) {
				cout << 1 << " " << month + 1 << " " << year << endl;
			}
			else {
				cout << "Invalid date" << endl;
			}
		}
		else if (month == 2) {
			if (day == 28) {
				cout << 1 << " " << month + 1 << " " << year << endl;
			}
			else {
				cout << day + 1 << " " << month << " " << year << endl;
			}
		}
		else {
			cout << "Invalid date" << endl;
		}
	}

	return 0;
}