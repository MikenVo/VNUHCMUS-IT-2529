#include <iostream>

using namespace std;

int RegularSum(int n) {
	if (n == 1) {
		return 1;
	}
	return n + RegularSum(n - 1);
}

int SquareSum(int n) {
	int result = 0;
	for (int i = 0; i <= n; i++) {
		result += i * i;
	}
	return result;
}

float FracSum(int n) {
	float result = 0;
	for (float i = 1.0f; i <= n; i++) {
		result += (1 / i);
	}
	return result;
}

int RegularProduct(int n) {
	if (n == 1) {
		return 1;
	}
	return n * RegularProduct(n - 1);
}

int Fractorial(int n) {
	if (n == 1) {
		return 1;
	}
	return n * Fractorial(n - 1);
}

int FractorialSum(int n) {
	if (n == 1) {
		return 1;
	}
	return Fractorial(n) + FractorialSum(Fractorial(n - 1));
}

int main() {
	int n; cin >> n;

	cout << "S = " << RegularSum(n) << endl;
	cout << "S = " << SquareSum(n) << endl;
	cout << "S = " << FracSum(n) << endl;
	cout << "S = " << RegularProduct(n) << endl;
	cout << "S = " << FractorialSum(n) << endl;

	return 0;
}