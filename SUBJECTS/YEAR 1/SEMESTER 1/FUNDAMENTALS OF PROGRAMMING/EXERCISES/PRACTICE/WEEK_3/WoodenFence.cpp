#include <iostream>

using namespace std;

int main() {
	int T;

	cin >> T;

	for (int i = T; i > 0; i--) {
		int n, x, y;
		bool valid = false;

		cin >> n >> x >> y;

		int white = n / 2; int black = white + 1;

		if (x >= black && y >= white) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}

	return 0;
}