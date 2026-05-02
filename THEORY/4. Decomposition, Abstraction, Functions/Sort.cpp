#include <iostream>

using namespace std;

void swap(float& a, float& b) {
	int t = a;
	a = b;
	b = t;
}

void sort(float arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i] < arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
}

int main() {
	int n; cin >> n;
	float l[n];

	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	sort(l, n);

	for (int i = 0; i < n; i++) {
		cout << l[i] << " ";
	}

	return 0;
}