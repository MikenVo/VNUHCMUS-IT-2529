#include <iostream>

using namespace std;

int main() {
	int r, c; cout << "Type the number of rows and columns (respectively): "; cin >> r >> c;
	int k; cout << "Type the target element: "; cin >> k;
	int l[r][c];

	cout << "Type the numbers: ";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> l[i][j];
		}
	}

	bool Found = false;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (k == l[i][j]) {
				Found = true;
				break;
			}
		}

		if (Found) {
			break;
		}
	}

	if (Found) {
		cout << "Found!!!" << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}