#include <iostream>

using namespace std;

bool HasSeven(int num) {
	int remainder;

	remainder = num % 10;
	if (remainder == 7) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int x,
		hh,
		mm;

	cin >> x;
	cin >> hh >> mm;

	if (HasSeven(hh) || HasSeven(mm)) {
		cout << 0 << endl;
	}
	else {
		int output = 0;

		while (true) {
			if (HasSeven(hh) || HasSeven(mm)) {
				cout << output << endl;
				break;
			}
			else {
				mm -= x;
				
				if (mm < 0) {
					mm = 60 + mm;
					hh--;
					if (hh < 0) {
						hh = 23;
					}
					output++;
				}
				else {
					output++;
				}
			}

		}
	}
}