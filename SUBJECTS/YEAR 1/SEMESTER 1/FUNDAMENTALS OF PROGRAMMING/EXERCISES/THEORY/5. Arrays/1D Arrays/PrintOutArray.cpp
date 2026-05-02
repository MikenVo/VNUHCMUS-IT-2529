#include <iostream>

using namespace std;

int main() {
	int n; cout << "Type the number of elements: "; cin >> n;
	int a[n];

	cout << "Input number: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cout << "Number " << i + 1 << ": " << a[i] << endl;
	}

	return 0;
}