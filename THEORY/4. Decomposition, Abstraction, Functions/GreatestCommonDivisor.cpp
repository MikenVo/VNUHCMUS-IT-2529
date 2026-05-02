#include <iostream>

using namespace std;

int GCD(int a, int b) {
	if (a > b) {
		if (a % b == 0) {
			return b;
		}
		else {
			while (true) {
				int r = a % b;
				a = b;
				b = r;

				if (a % b == 0) {
					return b;
				}
			}
		}
	}
	else if (a < b) {
		if (b % a == 0) {
			return a;
		}
		else {
			while (true) {
				int r = b % a;
				b = a;
				a = r;

				if (b % a == 0) {
					return a;
				}
			}
		}
	}
	else {
		return a;
	}
}

int main() {
	int a, b; cin >> a >> b;

	cout << GCD(a, b) << endl;;

	return 0;
}