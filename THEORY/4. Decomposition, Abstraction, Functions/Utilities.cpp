#include <iostream>
#include <cmath>

using namespace std;

int reverse(int n) {
	int digits = 0; int store = n;

	for (int i = 0; store > 0; i++) {
		digits++;
		store /= 10;
	}

	store = n; int result = 0;

	for (int i = digits; store > 0; i--) {
		result += (store % 10) * pow(10, i - 1);
		store /= 10;
	}

	return result;
}

bool IsSymmetric(int n) {
	if (n == reverse(n)) {
		return true;
	}
	else {
		return false;
	}
}

bool IsPerfectSquare(int n) {
	bool Perfect = false;
	if (n == 0 || n == 1) {
		return true;
	}
	else {
		for (int i = 2; i < n; i++) {
			if (i * i == n) {
				Perfect = true;
			}
		}
		return Perfect;
	}
}

bool IsPrime(int n) {
	bool Prime = true;
	if (n == 0 || n == 1 || n < 0) {
		return false;
	}
	else {
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				Prime = false;
				break;
			}
		}
		return Prime;
	}
}

int SumOddNum(int n) {
	int result = 0;
	for (int i = 0; i <= n; i++) {
		if (i % 2 != 0) {
			result += i;
		}
	}
	return result;
}

int SumPrimeNum(int n) {
	int result = 0;
	for (int i = 2; i <= n; i++) {
		if (IsPrime(i)) {
			result += i;
		}
	}
	return result;
}

int SumPerfectSquareNum(int n) {
	int result = 0;
	for (int i = 0; i <= n; i++) {
		if (IsPerfectSquare(i)) {
			result += i;
		}
	}
	return result;
}

int main() {
	int n; cin >> n;

	// 6 - a
	cout << "Inverse: " << reverse(n) << endl;

	// 6 - b
	if (IsSymmetric(n) == false) {
		cout << "Symmetric: False" << endl;
	}
	else {
		cout << "Symmetric: True" << endl;
	}

	// 6 - c
	if (IsPerfectSquare(n) == false) {
		cout << "Perfect Square: False" << endl;
	}
	else {
		cout << "Perfect Square: True" << endl;
	}

	// 6 - d
	if (IsPrime(n) == false) {
		cout << "Prime Number: False" << endl;
	}
	else {
		cout << "Prime Number: True" << endl;
	}

	// 6 - e
	cout << "Sum of odd numbers in n: " << SumOddNum(n) << endl;

	// 6 - f
	cout << "Sum of prime numbers in n: " << SumPrimeNum(n) << endl;

	// 6 - g
	cout << "Sum of perfect square numbers in n: " << SumPerfectSquareNum(n) << endl;

	return 0;
}