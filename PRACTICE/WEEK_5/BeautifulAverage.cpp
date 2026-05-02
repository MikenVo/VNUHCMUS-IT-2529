#include <iostream>

using namespace std;

int main() {
	int time;
	cin >> time;

	while (time > 0) {
		int len;
		cin >> len;
		int m = len - 1;

		int li[len];

		for (int i = 0; i < len; i++) {
			cin >> li[i];
		}

		int result = 0;
		for (int i = 0; i < len; i++) {
			result += li[i];
		}

		result /= len;

		int compare = 0;

		while (m > 0) {
			for (int j = 0; j <= (len - m); j++) {
				int l = j;
				int r = l + (m - 1);

				for (int d = l; d <= r; d++) {
					compare += li[d];
				}

				compare /= m;

				if (compare > result) {
					result = compare;
					compare = 0;
				}
				else {
					compare = 0;
				}
			}

			m--;
		}

		cout << result << endl;

		time--;
	}

	return 0;
}