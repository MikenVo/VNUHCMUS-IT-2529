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
	int a[n]; bool allPrime = true;

	cout << "Type numbers: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		if (!IsPrime(a[i])) {
			allPrime = false;
			break;
		}
	}

	if (allPrime) {
		cout << "Every number in the array is a prime" << endl;
	}
	else {
		cout << "Not every number in the array is a prime" << endl;
	}

	return 0;
}
