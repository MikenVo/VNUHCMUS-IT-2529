#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	int l[n];
	int largestodd = 0, smallesteven = 2;

	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	bool foundodd = false, foundeven = false;

	for (int i = 0; i < n; i++) {
		if (l[i] % 2 == 0 && l[i] <= smallesteven) {
			smallesteven = l[i];
			foundeven = true;
		}
		else if (l[i] % 2 != 0 && l[i] > largestodd) {
			largestodd = l[i];
			foundodd = true;
		}
	}

	if (foundeven && foundodd) {
		cout << smallesteven << endl;
		cout << largestodd << endl;
	}
	else if (foundeven && !foundodd) {
		cout << smallesteven << endl;
		cout << "No odd number" << endl;
	}
	else if (!foundeven && foundodd) {
		cout << "No even number" << endl;
		cout << largestodd << endl;
	}

	return 0;
}