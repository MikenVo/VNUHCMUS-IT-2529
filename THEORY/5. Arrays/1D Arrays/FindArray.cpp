#include <iostream>

using namespace std;

int main() {
	int n; cout << "Type number of elements: "; cin >> n;
	int k; cout << "Type a number that you want to find: "; cin >> k;
	int a[n]; bool Found = false;

	cout << "Input number: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		if (k == a[i]) {
			Found = true;
		}
	}

	if (Found) {
		cout << "Found!" << endl;
	}
	else {
		cout << Found - 1 << endl;
	}

	return 0;
}