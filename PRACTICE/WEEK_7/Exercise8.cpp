#include <iostream>

using namespace std;

int main() {
	int n; cout << "Type the number of elements: "; cin >> n;
	int arr[n], newarr[n], last = 0, after = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int a = n, m, counter = 0, l;
	while (a > 0) {
		for (int i = 0; i < n - (a - 1); i++) {
			for (int j = i; j < a + i; j++) {
				after += arr[j];
				m = j;
			}

			if (after > last) {
				last = after;

				for (int i = 0; i < n; i++) {
					newarr[i] = 0;
				}

				int z;
				if (a > m) {
					z = a - m - 1;
				}
				else if (m > a) {
					z = m - a + 1;
				}
				else {
					z = a - (m - 1);
				}

				for (int i = z; i < z + a; i++) {
					newarr[counter] = arr[i];
					counter++;
				}

				counter = 0;
				l = a;
				after = 0;
			}
			else {
				after = 0;
			}
		}
		a--;
	}

	cout << last << endl;
	for (int i = 0; i < l; i++) {
		cout << newarr[i] << " ";
	}

	return 0;
}