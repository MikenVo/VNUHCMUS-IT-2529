#include <iostream>

using namespace std;

int main() {
	int n, m; cout << "Type the number of rows and columns (respectively): "; cin >> n >> m; // n represente
	int l[n][m];

	cout << "Type the numbers: ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> l[i][j];
		}
	}

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			cout << l[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}