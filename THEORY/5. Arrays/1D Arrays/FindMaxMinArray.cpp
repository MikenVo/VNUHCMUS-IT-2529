#include <iostream>

using namespace std;

int FindMax(int l[], int n) {
	int max = l[0];

	for (int i = 0; i < n; i++) {
		if (max < l[i]) {
			max = l[i];
		}
	}
	return max;
}

int FindMin(int l[], int n) {
	int min = l[0];

	for (int i = 0; i < n; i++) {
		if (min > l[i]) {
			min = l[i];
		}
	}
	return min;
}

int main() {
	int n; cout << "Type the number of elements: "; cin >> n;
	int l[n];

	cout << "Type the numbers: ";
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	cout << "Max: " << FindMax(l, n) << endl;
	cout << "Min: " << FindMin(l, n) << endl;

	return 0;
}