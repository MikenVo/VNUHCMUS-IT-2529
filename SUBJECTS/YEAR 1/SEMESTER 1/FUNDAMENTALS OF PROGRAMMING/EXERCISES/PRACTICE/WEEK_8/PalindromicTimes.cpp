#include <iostream>
#include <cstring>
#include <cctype> // toupper()
#include <cmath>

using namespace std;

// 12:21

int Convert(char num, char num2) {
	int total = 0;

	if (isdigit(num)) {
		total = (num - '0') * 10 + (num2 - '0');
	}

	return total;
}

int reverse(int num) {
	int total = 0;

	for (int i = 2; num > 0; i--) {
		total += (num % 10) * pow(10, i - 1);
		num /= 10;
	}

	return total;
}

int main() {
	char time[6];

	cin.getline(time, 6);

	// HH:MM
	// Reverse the HH, if MM > HH then HH + 1. Else, print the answer

	int hours = Convert(time[0], time[1]);
	int minutes = Convert(time[3], time[4]);

	if ((hours >= 0 && hours <= 5) || (hours >= 10 && hours <= 15) || (hours >= 20 && hours <= 23)) {
		if (reverse(hours) == minutes) {
			if (hours + 1 == 24) {
				cout << "00:00" << endl;
			}
			else if (hours + 1 == 16) {
				cout << "20:02" << endl;
			}
			else {
				if (hours + 1 < 10 && reverse(hours + 1) < 10) {
					cout << 0 << hours + 1 << ":" << 0 << reverse(hours + 1) << endl;
				}
				else if (hours + 1 >= 10 && reverse(hours + 1) < 10) {
					cout << hours + 1 << ":" << 0 << reverse(hours + 1) << endl;
				}
				else if (hours + 1 < 10 && reverse(hours + 1) >= 10) {
					cout << 0 << hours + 1 << ":" << reverse(hours + 1) << endl;
				}
				else {
					cout << hours + 1 << ":" << reverse(hours + 1) << endl;
				}
			}
		}
		else if (reverse(hours) < minutes) {
			if (hours + 1 == 24) {
				cout << "00:00" << endl;
			}
			else if (hours + 1 == 16) {
				cout << "20:02" << endl;
			}
			else {
				if (hours + 1 < 10 && reverse(hours + 1) < 10) {
					cout << 0 << hours + 1 << ":" << 0 << reverse(hours + 1) << endl;
				}
				else if (hours + 1 >= 10 && reverse(hours + 1) < 10) {
					cout << hours + 1 << ":" << 0 << reverse(hours + 1) << endl;
				}
				else if (hours + 1 < 10 && reverse(hours + 1) >= 10) {
					cout << 0 << hours + 1 << ":" << reverse(hours + 1) << endl;
				}
				else {
					cout << hours + 1 << ":" << reverse(hours + 1) << endl;
				}
			}
		}
		else if (reverse(hours) > minutes) {
			if (hours < 10 && reverse(hours) < 10) {
				cout << 0 << hours << ":" << 0 << reverse(hours) << endl;
			}
			else if (hours >= 10 && reverse(hours) < 10) {
				cout << hours << ":" << 0 << reverse(hours) << endl;
			}
			else if (hours < 10 && reverse(hours) >= 10) {
				cout << 0 << hours << ":" << reverse(hours) << endl;
			}
			else {
				cout << hours << ":" << reverse(hours) << endl;
			}
		}
	}
	else if (hours >= 6 && hours <= 9) {
		cout << "10:01" << endl;
	}
	else {
		cout << "20:02" << endl;
	}
	return 0;
}