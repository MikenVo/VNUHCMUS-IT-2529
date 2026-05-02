#include <iostream>

using namespace std;

bool IsPrime(int n) {
	bool Prime = true;
	if (n == 0 || n == 1 || n < 0) {
		return false;
	}
	else {
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				Prime = false;
				break;
			}
		}
	}
	return Prime;
}

int main() {
	int n; cout << "Type the number of elements: "; cin >> n;
	int n2 = 0;
	int a[n];

	cout << "Type the numbers: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (IsPrime(a[i])) {
			n2++;
		}
	}

	int b[n2]; int j = 0;

	for (int i = 0; i < n; i++) {
		if (IsPrime(a[i])) {
			b[j] = a[i];
			j++;
		}
	}

	for (int i = 0; i < n2; i++) {
		cout << b[i] << " ";
	}

	return 0;
}