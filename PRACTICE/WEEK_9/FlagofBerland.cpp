#include <iostream>

using namespace std;

int main() {
	int n, m; cin >> n >> m;

	char** flag = new char* [n];
	for (int arr = 0; arr < n; arr++) {
		flag[arr] = new char[m];
	}

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			cin >> flag[row][col];
		}
		flag[row][m] = '\0';
	}

	int numberofstripe = 0;
	char checkletter = '\0';
	bool isValid = true;

	if (n % 3 == 0 && m % 3 != 0) {
		numberofstripe = n / 3;
		int index = 0;

		while (index < n) {
			for (int row = index; row < numberofstripe; row++) {
				checkletter = flag[row][0];
				for (int col = 0; col < m - 1; col++) {
					if (flag[row][col + 1] != checkletter) {
						isValid = false;
						break;
					}
				}

				if (!isValid) {
					cout << "NO" << endl;
					break;
				}
			}

			index += numberofstripe;
		}
	}
	else if (n % 3 != 0 && m % 3 == 0) {
		numberofstripe = m / 3;
		int index = 0;

		while (index < m) {
			for (int col = index; col < numberofstripe; col++) {
				checkletter = flag[0][col];
				for (int row = 0; row < n - 1; row++) {
					if (flag[row+1][col] != checkletter) {
						isValid = false;
						break;
					}
				}

				if (!isValid) {
					cout << "NO" << endl;
					break;
				}
			}

			index += numberofstripe;
		}
	}
	else if (n % 3 == 0 && m % 3 == 0) {
		numberofstripe = n / 3;
		int index = 0;

		while (index < n)
		{
			for (int row = index; row < numberofstripe; row++)
			{
				checkletter = flag[row][0];
				for (int col = 0; col < m - 1; col++)
				{
					if (flag[row][col + 1] != checkletter)
					{
						isValid = false;
						break;
					}
				}
			}

			index += numberofstripe;
		}

		if (!isValid) {
			numberofstripe = m / 3;
			index = 0;

			while (index < m)
			{
				for (int col = index; col < numberofstripe; col++)
				{
					checkletter = flag[0][col];
					for (int row = 0; row < n - 1; row++)
					{
						if (flag[row + 1][col] != checkletter)
						{
							isValid = false;
							break;
						}
						else
						{
							isValid = true;
						}
					}

					if (!isValid) {
						cout << "NO" << endl;
						break;
					}
				}

				index += numberofstripe;
			}
		}
	}
	else {
		isValid = false;
		cout << "NO" << endl;
	}

	if (isValid) {
		cout << "YES" << endl;
	}


	for (int arr = 0; arr < n; arr++) {
		delete[] flag[arr];
	}
	delete[] flag;

	return 0;
}