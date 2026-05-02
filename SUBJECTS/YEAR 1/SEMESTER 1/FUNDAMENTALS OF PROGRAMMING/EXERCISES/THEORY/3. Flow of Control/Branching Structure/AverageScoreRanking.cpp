#include <iostream>

using namespace std;

int main() {
	

	float a, b, c;

	while (true) {
		cout << "Type 3 students' scores: "; cin >> a >> b >> c;

		if (a < 0 || b < 0 || c < 0 || a > 10 || b > 10 || c > 10) {
			cout << "ERROR" << endl;
			continue;
		}
		else {
			if (a > b && a > c) {
				a = 1;
				if (b > c) {
					b = 2;
					c = 3;
				}
				else if (c > b) {
					b = 3;
					c = 2;
				}
				else {
					b = c = 2;
				}
			}
			else if (b > a && b > c) {
				b = 1;
				if (a > c) {
					a = 2;
					c = 3;
				}
				else if (c > a) {
					a = 3;
					c = 2;
				}
				else {
					a = c = 2;
				}
			}
			else if (c > a && c > b) {
				c = 1;
				if (a > b) {
					a = 2;
					b = 3;
				}
				else if (b > a) {
					a = 3;
					b = 2;
				}
				else {
					a = b = 2;
				}
			}
			else {
				if (b == c) {
					if (b > a) {
						b = c = 1;
						a = 2;
					}
					else {
						b = c = 2;
						a = 1;
					}
				}
				else if (a == b) {
					if (b > c) {
						b = a = 1;
						c = 2;
					}
					else {
						b = a = 2;
						c = 1;
					}
				}
				else {
					if (c > b) {
						a = c = 1;
						b = 2;
					}
					else {
						a = c = 2;
						b = 1;
					}
				}

			}
			cout << "Ranking: " << a << " " << b << " " << c << " " << endl;
			break;
		}
	}
	
	return 0;
}