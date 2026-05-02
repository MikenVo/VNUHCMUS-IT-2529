#include <iostream>

using namespace std;

int FindMinimum(float l[], int n) {
	float smallest = l[0];

	for (int i = 0; i < n; i++) {
		if (l[i] < smallest) {
			smallest = l[i];
		}
	}

	return smallest;
}

int main() {
	int n = 4;
	float l[n];

	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	cout << FindMinimum(l, n) << endl;

	return 0;
}