#include <iostream>

using namespace std;

int main() {
	int n = 0, m = 0, k = 0;

	cin >> n >> m >> k;

	if (m < n || k < n) {
		cout << "No" << endl;
	}
	else {
		if ((m+k) / 2 >= n) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

	return 0;
}