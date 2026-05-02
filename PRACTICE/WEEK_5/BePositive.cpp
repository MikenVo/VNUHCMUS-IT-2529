#include <iostream>

using namespace std;

int main() {
	int time;
	cin >> time;

	for (int j = 0; j < time; j++) {
		int t; int output = 0; int multiply = 1;
		cin >> t;

		int l[t];

		for (int i = 0; i < t; i++) {
			cin >> l[i];
			if (l[i] == 0) {
				l[i]++;
				output++;
				multiply *= l[i];
			}
			else {
				multiply *= l[i];
			}
		}

		while (true) {
			if (multiply > 0) {
				cout << output << endl;
				break;
			}
			else {
				for (int i = 0; i < t; i++) {
					if (l[i] == -1) {
						l[i] += 2;
						output += 2;
						break;
					}
				}

				multiply = 1;

				for (int i = 0; i < t; i++) {
					multiply *= l[i];
				}
			}
		}
	}

	return 0;
}