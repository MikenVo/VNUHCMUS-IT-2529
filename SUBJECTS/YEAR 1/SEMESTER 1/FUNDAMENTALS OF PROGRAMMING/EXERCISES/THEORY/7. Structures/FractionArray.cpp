#include <iostream>
using namespace std;

struct Frac {
	double numerator;
	double denomerator;
};

int gcd(double firstnum, double secondnum) {
	int fnum = abs(firstnum), snum = abs(secondnum);

	int remainder = fnum % snum;

	while (remainder != 0) {
		fnum = snum;
		snum = remainder;
		remainder = fnum % snum;
	}

	return snum;
}

bool isLarger(Frac firstnum, Frac secondnum) {
	double fnum = firstnum.numerator / firstnum.denomerator;
	double snum = secondnum.numerator / secondnum.denomerator;

	if (fnum > snum) {
		return true;
	}
	return false;
}

void sorted(Frac arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (isLarger(arr[j], arr[j + 1])) {
				Frac temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int n; cin >> n;
	Frac* arr = new Frac[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i].numerator;
		cin >> arr[i].denomerator;
		if (arr[i].denomerator == 0) {
			return 1;
		}
	}

	int positive = 0, negative = 0, GCD;
	bool found = false;
	double foundnumer = 0, founddenom = 0;
	for (int i = 0; i < n; i++) {
		GCD = gcd(arr[i].numerator, arr[i].denomerator);
		// Reduce the fraction
		if (arr[i].numerator <= 0 && arr[i].denomerator < 0) {
			arr[i].numerator /= -GCD;
			arr[i].denomerator /= -GCD;
		}
		else if ((arr[i].numerator <= 0 && arr[i].denomerator > 0) || (arr[i].numerator > 0 && arr[i].denomerator > 0)) {
			arr[i].numerator /= GCD;
			arr[i].denomerator /= GCD;
		}
		else if (arr[i].numerator >= 0 && arr[i].denomerator < 0) {
			arr[i].numerator /= -GCD;
			arr[i].denomerator /= -GCD;
		}

		// Check negative/positive
		if ((arr[i].numerator <= 0 && arr[i].denomerator > 0) ||
			(arr[i].numerator >= 0 && arr[i].denomerator < 0)) {
			negative++;
		}
		else {
			positive++;
			if (!found) {
				foundnumer = arr[i].numerator;
				founddenom = arr[i].denomerator;
				found = true;
			}
		}
	}

	int largest = 0;
	for (int queue = 1; queue < n; queue++) {
		if (!isLarger(arr[largest], arr[queue])) {
			largest = queue;
		}
	}

	int smallest = 0;
	for (int queue = 1; queue < n; queue++) {
		if (isLarger(arr[smallest], arr[queue])) {
			smallest = queue;
		}
	}

	cout << "Reduced array: ";
	cout << "[";
	for (int frac = 0; frac < n; frac++) {
		if (frac == n - 1) {
			cout << arr[frac].numerator << "/" << arr[frac].denomerator;
			break;
		}
		cout << arr[frac].numerator << "/" << arr[frac].denomerator << ", ";
	}
	cout << "]" << endl;
	cout << endl;

	cout << "Positive fractions: " << positive << endl;
	cout << "Negative fractions: " << negative << endl;
	cout << endl;

	if (found) {
		cout << "The first positive fraction: " << foundnumer << "/" << founddenom << endl;
	}
	else {
		cout << "The first positive fraction: NULL" << endl;
	}
	cout << endl;

	cout << "The largest fraction: " << arr[largest].numerator << "/" << arr[largest].denomerator << endl;
	cout << "The smallest fraction: " << arr[smallest].numerator << "/" << arr[smallest].denomerator << endl;
	cout << endl;

	sorted(arr, n);

	cout << "Sorted array: ";
	cout << "[";
	for (int frac = 0; frac < n; frac++) {
		if (frac == n - 1) {
			cout << arr[frac].numerator << "/" << arr[frac].denomerator;
			break;
		}
		cout << arr[frac].numerator << "/" << arr[frac].denomerator << ", ";
	}
	cout << "]" << endl;

	return 0;
}