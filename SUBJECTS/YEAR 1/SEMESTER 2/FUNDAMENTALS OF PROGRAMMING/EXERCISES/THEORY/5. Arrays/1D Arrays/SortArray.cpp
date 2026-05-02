#include <iostream>

using namespace std;

void sort(int l[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (l[j] > l[j + 1]) {
				int t = l[j];
				l[j] = l[j + 1];
				l[j + 1] = t;
			}
		}
	}
}

int main() {
	int n; cout << "Type the number of elements: "; cin >> n;
	int l[n];

	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	sort(l, n);

	cout << "Sort: ";
	for (int i = 0; i < n; i++) {
		cout << l[i] << " ";
	}

	return 0;
}