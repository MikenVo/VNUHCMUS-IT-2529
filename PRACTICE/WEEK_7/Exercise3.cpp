#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	int l[n];
	bool swapped = false;

	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	for (int i = 0; i < n; i++) {
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (l[j] > l[j + 1]) {
				int t = l[j];
				l[j] = l[j + 1];
				l[j + 1] = t;
				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << l[i] << " ";
	}

	return 0;
}