#include <iostream>

using namespace std;

int main() {
	int n, pos, l, r; cin >> n >> pos >> l >> r;

	// Keep all
	if (l == 1 && r == n) {
		cout << 0 << endl;
	}
	else if (l == 1 && r < n) {
		cout << abs(pos - r) + 1 << endl;
	}
	else if (l > 1 && r == n) {
		cout << abs(pos - l) + 1 << endl;
	}
	else if (l > 1 && r < n) {
		int first = abs(pos - l) + 1 + abs(l - r) + 1;
		int second = abs(pos - r) + 1 + abs(r - l) + 1;

		cout << min(first, second) << endl;
	}

	return 0;
}