#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	int l[n];

	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	int s = 0, e = n - 1;
	if (n % 2 != 0) {
		while (s != e) {
			int t = l[s];
			l[s] = l[e];
			l[e] = t;
			s++;
			e--;
		}
	}
	else {
		while (s <= n / 2 && e >= n / 2) {
			// 1 2 3 4 -> 4 3 2 1
			int t = l[s];
			l[s] = l[e];
			l[e] = t;
			s++;
			e--;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << l[i] << " ";
	}

	return 0;
}