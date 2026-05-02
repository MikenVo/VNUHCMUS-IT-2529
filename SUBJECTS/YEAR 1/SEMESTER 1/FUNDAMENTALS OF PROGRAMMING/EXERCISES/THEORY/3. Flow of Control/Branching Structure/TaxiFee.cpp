#include <iostream>

using namespace std;

int main() {
	int nkm;
	cout << "Type the number of kilometers that you have travelled: "; cin >> nkm;

	if (nkm == 0) {
		cout << "Get on the car!" << endl;
	}
	else if (nkm == 1) {
		cout << nkm * 15000 << " VND" << endl;
	}
	else if (nkm >= 2 && nkm <= 6) {
		cout << 1 * 15000 + (nkm - 1) * 13500 << " VND" << endl;
	}
	else if (nkm > 6 && nkm <= 120) {
		cout << 1 * 15000 + 4 * 13500 + (nkm - 5) * 11000 << " VND" << endl;
	}
	else if (nkm > 120) {
		// Use long long to handle overflow
		long long base_price = 15000 + 4LL * 13500 + (nkm - 5LL) * 11000; // LL is forcing the intergers to be long longs
		long long result = base_price * 90 / 100;
		cout << result << " VND" << endl;
	}

	return 0;
}