#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	int k; cin >> k;
	int l[n], c = 0;

	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	if (l[n - 1] == k) {
		l[n - 1] = 0;
		c++;
	}

	for (int i = 0; i < n; i++) {
		if (l[i] == k) {
			for (int j = i; j < n; j++) {
				l[j] = l[j + 1];
			}
			c++;
		}
	}

	n -= c;

	for (int i = 0; i < n; i++) {
		cout << l[i] << " ";
	}

	return 0;
}