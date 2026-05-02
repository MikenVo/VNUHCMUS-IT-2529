#include <iostream>
#include <cmath>

using namespace std;

void sorted(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int middle = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = middle;
			}
		}
	}
}

int main() {
	int numtc; cin >> numtc;

	for (int i = 0; i < numtc; i++) {
		int n; cin >> n;
		int l[n]; bool yes = false;

		for (int j = 0; j < n; j++) {
			cin >> l[j];
		}

		sorted(l, n);

		for (int a = 0; a < n; a++) {
			int pair = 0;

			for (int k = 0; k <= n-1; k++) {
				if (((l[a] % 2 == l[k] % 2) || (abs(l[a] - l[k]) == 1)) && a != k) {
					pair++;
				}
			}

			if (pair == 1) {
				yes = true;
			}
		}

		if (yes) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}