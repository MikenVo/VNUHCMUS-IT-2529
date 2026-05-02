#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int numl; cin >> numl;
	int l[numl];

	for (int i = 0; i < numl; i++) {
		cin >> l[i];
	}

	int f = 0, s = 1, bool yes = false;
	sort(l, l + numl);
	
	for (int i = s + 1; i < numl; i++) {
		if ((l[f] + l[s] > l[i]) && (l[f] + l[i] > l[s]) && (l[s] + l[i] > l[f]) && l[s] > 0 && l[f] > 0 && l[i] > 0) {
			cout << "YES" << endl;
			yes = true;
			break;
		}
		else {
			f++; s++;
		}
	}

	if (!yes) {
		cout << "NO" << endl;
	}

	return 0;
}