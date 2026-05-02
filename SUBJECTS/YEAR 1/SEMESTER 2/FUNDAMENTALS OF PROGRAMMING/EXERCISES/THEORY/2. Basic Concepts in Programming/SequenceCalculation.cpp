#include <iostream>

using namespace std;

int main() {
	int n;

	while (true) {
		cout << "Type a number: "; cin >> n;
		
		if (n > 0) {
			int total = 0;

			for (int i = 1; i <= n; i++) {
				total += i;
			}

			cout << "Total: " << total << endl;
			break;
		}
		else {
			cout << "ERROR" << endl;
			continue;
		}
	}

	return 0;
}