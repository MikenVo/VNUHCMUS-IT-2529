#include <iostream>

using namespace std;

bool IsInc(int newarr[], int n) {
	bool increasing = false, decreasing = false;
	for (int i = 0; i < n; i++) {
		if (newarr[i] < newarr[i + 1]) {
			increasing = true;
		}
		else if (newarr[i] > newarr[i + 1]) {
			decreasing = true;
		}
	}

	if (increasing && !decreasing) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int n; cin >> n;
	int newn = 1; int idx = 0;
	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int a = n, newarr[a];

	while (a > 0) {
		for (int i = 0; i < n - (a - 1); i++) {
			for (int j = i, k = 0; j < a + i, k < a; j++, k++) {
				newarr[k] = arr[j];
			}

			if (IsInc(newarr, a)) {
				break;
			}
		}

		if (IsInc(newarr, a)) {
			break;
		}

		a--;
	}

	for (int i = 0; i < a; i++) {
		cout << newarr[i] << " ";
	}

	return 0;
}