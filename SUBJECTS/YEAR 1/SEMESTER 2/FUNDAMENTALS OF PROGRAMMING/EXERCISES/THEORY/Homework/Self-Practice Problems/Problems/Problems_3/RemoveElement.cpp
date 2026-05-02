#include <iostream>

using namespace std;

int removeElement(int l[], int n, int val) {
	int remove = 0;
	for (int i = 0; i < n; i++) {
		if (val == l[i]) {
			remove++;
			l[i] = l[i + 1];
		}
	}

	return remove;
}

int main() {
	int n; cin >> n;
	int l[n], val; cin >> val;

	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	int r = removeElement(l, n, val);

	cout << n - r << endl;
	cout << "[";
	for (int i = 0; i < n - r; i++) {
		cout << i << ", ";
	}
	cout << "]";

	return 0;
}