#include <iostream>

using namespace std;

void Sort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		bool swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int m = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = m;
				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}
	}
}

int main() {
	int n; cin >> n;
	int k; cin >> k;
	int l[n], largest = 0;

	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	Sort(l, n);

	cout << l[n - k] << endl;

	return 0;
}