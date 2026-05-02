#include <iostream>

using namespace std;

int main() {
	int m, n; cout << "Input the number of rows and columns: "; cin >> m >> n;
	int a[m][n];

	cout << "Type the numbers: ";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	return 0;
}