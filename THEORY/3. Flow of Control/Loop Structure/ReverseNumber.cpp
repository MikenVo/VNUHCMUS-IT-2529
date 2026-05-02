#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n; cin >> n;
	int digits = 0, result = 0;
	int store = n; int remainder = 0;

	for (int i = 0; store > 0; i++) {
		digits++;
		store /= 10;
	}

	for (int i = digits; n > 0; i--) {
		remainder = n % 10;
		result += remainder * pow(10, i - 1);
		n /= 10;
	}

	cout << result << endl;

	return 0;
}