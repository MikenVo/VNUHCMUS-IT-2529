#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char s[1000005] = { 0 };
	char t[1000005] = { 0 };
	char u[1000005] = { 0 };
	cin >> s;

	int len = strlen(s);
	int indext = 0, indexu = 0;

	int count[100001] = { 0 };
	for (int k = 0; k < len; k++) {
		count[s[k] - 'a']++;
	}

	int i = 0;
	while (i < len) {
		t[indext++] = s[i];

		count[s[i] - 'a']--;
		i++;

		while (indext > 0) {
			bool NoSmaller = true;

			for (int k = 0; k < (t[indext - 1] - 'a'); k++) {
				if (count[k] > 0) {
					NoSmaller = false;
					break;
				}
			}

			if (NoSmaller) {
				u[indexu++] = t[indext - 1];
				indext--;
			}
			else {
				break;
			}
		}
	}

	while (indext > 0) {
		u[indexu++] = t[--indext];
	}

	cout << u << endl;

	return 0;
}