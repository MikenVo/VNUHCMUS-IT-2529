#include <iostream>

using namespace std;

int main() {
	int year;
	const int current_year = 2025;

	while (true) {
		cout << "Type your birth year: "; cin >> year;

		if (year >= 0) {
			cout << "Your age: " << current_year - year << endl;
			break;
		}
		else {
			cout << "ERROR" << endl;
			continue;
		}
	}

	return 0;
}