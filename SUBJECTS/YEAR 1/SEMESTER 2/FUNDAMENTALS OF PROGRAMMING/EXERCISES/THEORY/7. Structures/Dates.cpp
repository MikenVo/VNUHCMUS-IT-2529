#include <iostream>
using namespace std;

/*---- Define a struct ----*/
struct Date {
	int day;
	int month;
	int year;
};

int numofdays(int month, bool IsLeap) {
	if (month == 0 ||
		month == 1 ||
		month == 3 ||
		month == 5 ||
		month == 7 ||
		month == 8 ||
		month == 10 ||
		month == 12) {
		return 31;
	}
	else if (month == 2) {
		if (IsLeap) {
			return 29;
		}
		else {
			return 28;
		}
	}
	else {
		return 30;
	}
}

bool isLeap(int year) {
	bool IsLeap = false;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		IsLeap = true;
	}
	return IsLeap;
}

int main() {
	/*---- Input ----*/
	Date date;
	cout << "--------- Input ---------" << endl;
	cout << "Type a date in format \'DD MM YY\': "; cin >> date.day >> date.month >> date.year;

	/*---- Check if it is leap year ----*/
	bool IsLeap = isLeap(date.year);
	int ordinal = 1;
	int daycount = 1;
	int monthcount = 1;

	while (true) {
		if (daycount == date.day && monthcount == date.month) {
			break;
		}

		daycount++; ordinal++;
		if (daycount > numofdays(monthcount, IsLeap)) {
			daycount = 1;
			monthcount++;
		}
	}

	/*---- Find a date that is k days before/after the input date ----*/
	int k;
	cout << "Input the number of days before/after the input date: "; cin >> k;
	// Before
	int dayb = date.day;
	int monthb = date.month;
	int yearb = date.year;
	int numdayb = k;
	int numofleapyear = 0;

	for (int i = numdayb; i > 0; i--) {
		dayb--;
		if (dayb == 0) {
			monthb--;
			if (monthb == 0) {
				monthb = 12;
				yearb--;
			}

			dayb = numofdays(monthb, isLeap(yearb));
		}
	}

	// After
	int daya = date.day;
	int montha = date.month;
	int yeara = date.year;
	int numday = 0;

	while (numday != k) { // Stop when numday adds up to k
		if (k - numday <= numofdays(montha, isLeap(yeara))) { // If the difference between k and numday <= 31
			daya += k - numday; // We add that difference into daya
			numday += k - numday; // Update numday
			if (daya > numofdays(montha, isLeap(yeara))) { // To fix the day if it exceeds the number of days of the current month
				daya -= numofdays(montha, isLeap(yeara));
				montha++;
			}
		}
		else {
			numday += numofdays(montha, isLeap(yeara)) - daya + 1;
			daya += numofdays(montha, isLeap(yeara)) - daya + 1;
			if (daya > numofdays(montha, isLeap(yeara))) {
				daya = 1;
				montha++;
			}
		}

		if (montha > 12) {
			montha = 1;
			yeara++;
		}
	}

	Date date2;
	cout << "Type a second date in format \'DD MM YY\': "; cin >> date2.day >> date2.month >> date2.year;

	daycount = date.day;
	monthcount = date.month;
	int yearcount = date.year;
	int count = 0;

	while (true) {
		if (daycount == date2.day && monthcount == date2.month && yearcount == date2.year) {
			break;
		}

		daycount++; count++;
		if (daycount > numofdays(monthcount, isLeap(yearcount))) {
			monthcount++;
			daycount = 1;

			if (monthcount > 12) {
				monthcount = 1;
				yearcount++;
			}
		}
	}

	/*---- Output ----*/
	cout << endl;
	cout << "--------- Output ---------" << endl;

	cout << "1. Leap year" << endl;
	if (IsLeap) {
		cout << "Your year is a leap year" << endl;
	}
	else {
		cout << "Your year is not a leap year" << endl;
	}
	cout << endl;

	cout << "2. Calculate the ordinal number of a day" << endl;
	cout << date.day << "/" << date.month << "/" << date.year << " is day " << ordinal << endl;
	cout << endl;

	cout << "3. Calculate the date before/after the given date k days" << endl;
	cout << "The date before " << k << " days is " << dayb << "/" << monthb << "/" << yearb << endl;
	cout << "The date after " << k << " days is " << daya << "/" << montha << "/" << yeara << endl;
	cout << endl;

	cout << "4. Calculate the number of days between two days" << endl;
	cout << date.day << "/" << date.month << "/" << date.year << " is " << count << " days away from " << date2.day << "/" << date2.month << "/" << date2.year << endl;
	cout << endl;

	/*---- Compare two dates ----*/
	cout << "5. Compare two dates" << endl;
	if (date.year > date2.year) {
		cout << date.day << "/" << date.month << "/" << date.year << " is after " << date2.day << "/" << date2.month << "/" << date2.year << endl;
	}
	else if (date.year < date2.year) {
		cout << date.day << "/" << date.month << "/" << date.year << " is before " << date2.day << "/" << date2.month << "/" << date2.year << endl;
	}
	else {
		if (date.month > date2.month) {
			cout << date.day << "/" << date.month << "/" << date.year << " is after " << date2.day << "/" << date2.month << "/" << date2.year << endl;
		}
		else if (date.month < date2.month) {
			cout << date.day << "/" << date.month << "/" << date.year << " is before " << date2.day << "/" << date2.month << "/" << date2.year << endl;
		}
		else {
			if (date.day > date2.day) {
				cout << date.day << "/" << date.month << "/" << date.year << " is after " << date2.day << "/" << date2.month << "/" << date2.year << endl;
			}
			else if (date.day < date2.day) {
				cout << date.day << "/" << date.month << "/" << date.year << " is before " << date2.day << "/" << date2.month << "/" << date2.year << endl;
			}
			else {
				cout << date.day << "/" << date.month << "/" << date.year << " is equal to " << date2.day << "/" << date2.month << "/" << date2.year << endl;
			}
		}
	}

	return 0;
}