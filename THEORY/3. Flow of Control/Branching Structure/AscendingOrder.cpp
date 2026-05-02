#include <iostream>

using namespace std;

int main() {
	int a, b, c, d;

	cout << "Type 4 numbers: "; cin >> a >> b >> c >> d;

	int store;

	for (int i = 0; i < 3; i++) {
		// a
		if (a > b) {
			store = a;
			a = b;
			b = store;
		}
		else if (a > c) {
			store = a;
			a = c;
			c = store;
		}
		else if (a > d) {
			store = a;
			a = d;
			d = store;
		}

		// b
		if (b > c) {
			store = b;
			b = c;
			c = store;
		}
		else if (b > d) {
			store = b;
			b = d;
			d = store;
		}

		// c
		if (c > d) {
			store = c;
			c = d;
			d = store;
		}
	}
	
	cout << "Ascending order: " << a << " " << b << " " << c << " " << d << endl;

	return 0;
}