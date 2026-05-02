#include <iostream>

using namespace std;

bool isPrime(int n) {
	bool prime = true;
	if (n == 1 || n == 0) {
		return false;
	}
	else {
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				prime = false;
				break;
			}
		}
	}

	return prime;
}

int main() {
	int n, total = 0;

	while (true) {
		cin >> n;
		if (0 < n && n < 50) {
			break;
		}
		else {
			continue;
		}
	}

	for (int i = 0; i < n; i++) {
		if (isPrime(i)) {
			total += i;
		}
	}

	cout << total << endl;

	return 0;
}