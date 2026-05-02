#include <iostream>

using namespace std;

int main() {
	unsigned int a, b, n;

	while (true) {
		cin >> a >> b >> n;
		if (a < n && b < n) {
			break;
		}
		else {
			continue;
		}
	}
	
	int total = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if ((i % a == 0 && j % a == 0) && (i % b != 0 && j % b != 0) && (i + j < n)) {
				total = i + j;
				break;
			}
		}
	}

	cout << total << endl;

	return 0;
}