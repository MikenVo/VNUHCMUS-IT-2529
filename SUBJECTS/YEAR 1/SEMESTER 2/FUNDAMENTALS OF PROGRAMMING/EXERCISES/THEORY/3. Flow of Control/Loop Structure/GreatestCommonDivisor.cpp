#include <iostream>

using namespace std;

int main() {
	int a, b; cin >> a >> b;
	int remainder, result, divide;

	if (a > b) {
		while (true) {
			if (b % a == 0) {
				cout << a << endl;
				break;
			}
			else {
				remainder = b % a;
				b = a;
				a = remainder;
			}
		}
	}
	else if (b > a) {
		while (true) {
			if (a % b == 0) {
				cout << b << endl;
				break;
			}
			else {
				remainder = a % b;
				a = b;
				b = remainder;
			}
		}
	}
	else {
		cout << a << endl;
	}
}