#include <iostream>

using namespace std;

int main() {
	int n; cout << "Type a number: "; cin >> n;
	int l[n][n];

	cout << "Type the numbers: ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> l[i][j];
		}
	}

	cout << "Main Diagonal: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				cout << l[i][j] << " ";
			}
			else {
				cout << " " << " ";
			}
		}
		cout << endl;
	}

	cout << endl;

	cout << "Opposite Diagonal: " << endl;

	int c2 = n - 1, r2 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == r2 && j == c2) {
				cout << l[i][j] << " ";
				r2++; c2--;
			}
			else {
				cout << " " << " ";
			}
		}
		cout << endl;
	}

	return 0;
}