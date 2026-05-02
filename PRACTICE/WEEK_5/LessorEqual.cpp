#include <iostream>
#include <cmath>

using namespace std;

void sorted(int arr[], int n) {
	int middle;

	for (int i = 0; i < n; i++) {
		bool swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swapped = true;
				middle = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = middle;
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

	int l[n];
	
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	sorted(l, n);

	if (k == 0) {
		if (l[0] - 1 > 0) {
			cout << l[0] - 1 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	else {
		int result = l[k - 1];

		if (k < n && l[k] == result) {
			cout << -1 << endl;
		}
		else {
			cout << result << endl;
		}
	}

	return 0;
}