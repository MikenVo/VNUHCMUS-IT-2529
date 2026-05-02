#include <iostream>

using namespace std;

int main() {
	int n; cout << "Type the number of elements of the first array: "; cin >> n;
	int n2; cout << "Type the number of elements of the second array: "; cin >> n2;
	int n3 = n + n2;

	int a[n], b[n2], c[n3];

	cout << "Type the numbers for the first array: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << "Type the numbers for the second array: ";
	for (int i = 0; i < n2; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < n; i++) {
		c[i] = a[i];
	}

	int j = 0;

	for (int i = n; i < n3; i++) {
		c[i] = b[j];
		j++;
	}

	for (int i = 0; i < n3; i++) {
		cout << c[i] << " ";
	}

	return 0;
}