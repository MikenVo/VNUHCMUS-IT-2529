#include <iostream>

using namespace std;

int main() {
	int num;
	int n = 0;

	while (true) {
		cout << "Type a number: "; cin >> num;

		if (num > 1) {
			for (int i = 1; i <= num; i++) {
				if (num % i == 0) {
					n++;
				}
			}

			if (n == 2) {
				cout << num << " is a prime nunmber." << endl;
				break;
			}
			else {
				cout << num << " is not a prime number." << endl;
				break;
			}
		}
		else {
			cout << "ERROR" << endl;
			continue;
		}
	}

	return 0;
}