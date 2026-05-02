#include <iostream>
#include <cmath>

using namespace std;

bool IsInterestingNumber(int num) {
	int remainder = 0;
	int store = num;
	int total = 0;

	for (int i = 0; store > 0; i++) {
		remainder = store % 10;
		store /= 10;
		total += remainder;
	}

	if (total % 4 == 0) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int num = 0;
	cin >> num;

	while (true) {
		if (IsInterestingNumber(num)) {
			cout << num << endl;
			break;
		}
		else {
			num++;
		}
	}

	return 0;
}