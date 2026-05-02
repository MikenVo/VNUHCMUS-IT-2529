#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	int l[n];

	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	bool decreasing = false, increasing = false;

	for (int i = 0; i < n - 1; i++) {
		if (l[i] < l[i + 1]) {
			increasing = true;
		}
		else if (l[i] > l[i + 1]) {
			decreasing = true;
		}
	}

	if ((increasing && decreasing) || (!increasing && !decreasing)) {
		cout << "Regular" << endl;
	}
	else if (!increasing && decreasing) {
		cout << "Not increasing" << endl;
	}
	else {
		cout << "Not decreasing" << endl;
	}

	return 0;
}