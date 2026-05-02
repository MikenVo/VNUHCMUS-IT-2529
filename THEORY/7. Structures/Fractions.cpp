#include <iostream>

using namespace std;

// Define a struct with Fraction data type
struct Fraction {
	long long numerator;
	long long denominator;
};

int GCD(long long num1, long long num2) {
	if (num1 == 0 && num2 != 0) {
		return num2;
	}
	else if (num1 != 0 && num2 == 0) {
		return num1;
	}

	if (num1 > num2) {
		long long modulo = num1 % num2;
		while (modulo > 0) {
			num1 = num2;
			num2 = modulo;
			modulo = num1 % num2;
		}

		return num2;
	}
	else {
		long long modulo = num2 % num1;
		while (modulo > 0) {
			num2 = num1;
			num1 = modulo;
			modulo = num2 % num1;
		}

		return num1;
	}
}

/*---- Reduce a fraction ----*/
void reduce(Fraction& frac) {
	if (frac.numerator > 0 && frac.denominator > 0) {
		long long gcd = GCD(frac.numerator, frac.denominator);
		frac.numerator /= gcd;
		frac.denominator /= gcd;
	}
	else if (frac.numerator <= 0 && frac.denominator < 0) {
		long long gcd = GCD(abs(frac.numerator), abs(frac.denominator));
		frac.numerator /= -gcd;
		frac.denominator /= -gcd;
	}
	else {
		long long gcd = GCD(abs(frac.numerator), abs(frac.denominator));
		frac.numerator /= gcd;
		frac.denominator /= gcd;
	}
}

/*---- The addition of two fractions ----*/
void addition(Fraction& frac) {
	// Input the second fraction
	Fraction secondfrac;
	cout << "Type your numerator for the second fraction: "; cin >> secondfrac.numerator;
	cout << "Type your deomerator for the second fraction: "; cin >> secondfrac.denominator;

	// Check if the denominator of the second fraction is equal to 0
	if (secondfrac.denominator == 0) {
		cout << "ERROR" << endl;
		return;
	}

	// Calculate the least common multiple
	long long lcm = (frac.denominator * secondfrac.denominator) / GCD(frac.denominator, secondfrac.denominator);

	// Addition
	// For example: 3 / 4 + 1 / 6 = 11 / 12
	//				[4, 6] = 12
	//				3 = 3 * (12 / 4) + 1 * (12 / 6) = 11
	//				4 = 12
	// Final fraction: 11 / 12
	frac.numerator = frac.numerator * (lcm / frac.denominator) + secondfrac.numerator * (lcm / secondfrac.denominator);
	frac.denominator = lcm;

	// Reduce the fraction
	reduce(frac);
}

/*---- The subtraction of two fractions ----*/
void subtraction(Fraction& frac) {
	// Input the third fraction
	Fraction thirdfrac;
	cout << "Type your numerator for the third fraction: "; cin >> thirdfrac.numerator;
	cout << "Type your denominator for the third fraction: "; cin >> thirdfrac.denominator;

	// Check if the denominator is equal to 0
	if (thirdfrac.denominator == 0) {
		cout << "ERROR" << endl;
		return;
	}

	// Find the least common multiple
	long long lcm = (frac.denominator * thirdfrac.denominator) / GCD(frac.denominator, thirdfrac.denominator);

	// Subtraction
	// For example: 3 / 4 - 1 / 6 = 7 / 12
	//				[4, 6] = 12
	//				3 * (12 / 4) - 1 * (12 / 6) = 7
	//				4 = 12
	// Final fraction: 7 / 12
	frac.numerator = frac.numerator * (lcm / frac.denominator) - thirdfrac.numerator * (lcm / thirdfrac.denominator);
	frac.denominator = lcm;

	reduce(frac);
}

/*---- The multiplication of two fraction ----*/
void multiplication(Fraction& frac) {
	Fraction fourthfrac;
	cout << "Type your numerator for the fourth fraction: "; cin >> fourthfrac.numerator;
	cout << "Type your denominator for the fourth fraction: "; cin >> fourthfrac.denominator;

	if (fourthfrac.denominator == 0) {
		cout << "ERROR" << endl;
		return;
	}

	frac.numerator *= fourthfrac.numerator;
	frac.denominator *= fourthfrac.denominator;

	reduce(frac);
}

/*---- The division of two fraction ----*/
void division(Fraction& frac) {
	Fraction fifthfrac;
	cout << "Type your numerator for the fifth fraction: "; cin >> fifthfrac.numerator;
	cout << "Type your denominator for the fifth fraction: "; cin >> fifthfrac.denominator;

	if (fifthfrac.denominator == 0) {
		cout << "ERROR" << endl;
		return;
	}

	frac.numerator *= fifthfrac.denominator;
	frac.denominator *= fifthfrac.numerator;

	reduce(frac);
}

/*---- The comparison of two fraction ----*/
int comparison(Fraction frac, Fraction frac2) {
	if (frac2.denominator == 0) {
		cout << "ERROR" << endl;
		return -2;
	}

	int result;
	long long lcm = (frac.denominator * frac2.denominator) / GCD(frac.denominator, frac2.denominator);
	frac.numerator *= lcm / frac.denominator;
	frac2.numerator *= lcm / frac2.denominator;

	if (frac.numerator > frac2.numerator) {
		result = 1;
	}
	else if (frac.numerator == frac2.numerator) {
		result = 0;
	}
	else {
		result = -1;
	}

	return result;
}

int main() {
	bool isSimplified = false, isPositive = false;
	Fraction frac;

	/*---- Input a fraction ----*/
	cout << "Type your numerator: "; cin >> frac.numerator;
	cout << "Type your denominator: "; cin >> frac.denominator;
	if (frac.denominator == 0) {
		cout << "ERROR" << endl;
		return 1;
	}

	if ((frac.numerator < 0 && frac.denominator > 0) || (frac.numerator > 0 && frac.denominator < 0)) {
		isPositive = false;
	}
	else {
		isPositive = true;
	}

	if (GCD(abs(frac.numerator), abs(frac.denominator)) > 1) {
		isSimplified = false;
	}
	else {
		isSimplified = true;
	}

	reduce(frac);
	cout << endl;

	cout << "---- Addition ----" << endl;
	Fraction fracforadd = frac;
	addition(fracforadd);
	cout << endl;

	cout << "---- Subtraction ----" << endl;
	Fraction fracforsubtract = frac;
	subtraction(fracforsubtract);
	cout << endl;

	cout << "---- Multiplication ----" << endl;
	Fraction fracformultiply = frac;
	multiplication(fracformultiply);
	cout << endl;

	cout << "---- Division ----" << endl;
	Fraction fracfordivide = frac;
	division(fracfordivide);
	cout << endl;

	cout << "---- Comparison ----" << endl;
	Fraction fracforcompare;
	// Input fifth fraction
	cout << "Type your numerator for the fifth fraction: "; cin >> fracforcompare.numerator;
	cout << "Type your denominator for the fifth fraction: "; cin >> fracforcompare.denominator;
	int result = comparison(frac, fracforcompare);
	cout << endl;

	/*---- Output a fraction ----*/
	cout << endl;
	cout << "---- Output ----" << endl;
	cout << "Fraction: " << frac.numerator << " / " << frac.denominator << endl;

	/*---- Check if a fraction is simplified ----*/
	if (isSimplified) {
		cout << "The fraction is simplified" << endl;
	}
	else {
		cout << "The fraction is not simplified" << endl;
	}

	/*---- Check if a fraction is positive or negative ----*/
	if (isPositive) {
		cout << "The fraction is positive" << endl;
	}
	else {
		cout << "The fraction is negative" << endl;
	}

	cout << "Fraction addition: " << fracforadd.numerator << " / " << fracforadd.denominator << endl;
	cout << "Fraction subtraction: " << fracforsubtract.numerator << " / " << fracforsubtract.denominator << endl;
	cout << "Fraction multiplication: " << fracformultiply.numerator << " / " << fracformultiply.denominator << endl;
	cout << "Fraction division: " << fracfordivide.numerator << " / " << fracfordivide.denominator << endl;

	if (result == 1) {
		cout << "The fraction is greater than " << fracforcompare.numerator << " / " << fracforcompare.denominator;
	}
	else if (result == 0) {
		cout << "The fraction is equal to " << fracforcompare.numerator << " / " << fracforcompare.denominator;
	}
	else {
		cout << "The fraction is smaller than " << fracforcompare.numerator << " / " << fracforcompare.denominator;
	}

	return 0;
}