#include <iostream>
#include <cmath>

using namespace std;

int SimpleCalculation(int n) {
	int total = 0;
	
	for (int i = 1; i <= n; i++) {
		total += i;
	}

	return total;
}

int SquaredCalculation(int n) {
	int total = 0;

	for (int i = 1; i <= n; i++) {
		total += pow(i, 2);
	}

	return total;
}

float FractionCalculation(int n) {
	float total = 0;

	for (float i = 1; i <= n; i++) {
		total += 1 / i;
	}

	return total;
}

int Factorial(int n) {
	int product = 1;

	for (int i = 1; i <= n; i++) {
		product *= i;
	}

	return product;
}

int FactorialCalculation(int n) {
	int total = 0;

	for (int i = 1; i <= n; i++) {
		total += Factorial(i);
	}

	return total;
}

int main() {
	int n; cin >> n;
	
	cout << "a. " << "S = " << SimpleCalculation(n) << endl;
	cout << "b. " << "S = " << SquaredCalculation(n) << endl;
	cout << "c. " << "S = " << FractionCalculation(n) << endl;
	cout << "d. " << "S = " << Factorial(n) << endl;
	cout << "e. " << "S = " << FactorialCalculation(n) << endl;

	return 0;
}