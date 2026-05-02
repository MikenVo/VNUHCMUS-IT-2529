#include <iostream>

using namespace std;

int main() {
	int n; cout << "Type the number of elements: "; cin >> n;
	int a[n];

	cout << "Input number: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	return 0;
}