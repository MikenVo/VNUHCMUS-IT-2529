#include <iostream> // Use for input/output
#include <string> // To convert the number into string in order to retrieve the number of digits
#include <cmath> // To use the pow() function

using namespace std;

bool isPalindrome(int x) {
	int store = x; // Define a variable to get a copy of x
	int remainder = 0; // To store one digit in the number
	int total = 0; // Used to form the reversed number
	int digits = 0; // To identify the number of digits

	// Check if store is less than 0 (1)
	if (store < 0) {
		// If (1) true, return false
		/* Reason:
		* Negative numbers when be reversed is not a palindrome number.
		* For example: -121 -> 121- (not a palindrome number), -505 -> 505- (also not a palindrome number)
		*/
		return false;
	}
	else {
		// If (1) false, do a while loop to identify the number of digits in the number
		while (store > 0)
		{
			store /= 10;
			digits++;
		}
	}
		
	store = x; // Make another copy of x to store

	/*
	* We take a digit in the number and multiply with 10 to the power of i-1 (with i is the number of digits)
	* For example: 252
	* - digits = 3
	* - Remainder = 2
	* - Store = 25
	* - Total = 2 * 10^(3-1) = 200
	* - So on...
	*/
	for (int i = digits; i > 0; i--) {
		remainder = store % 10;
		store /= 10;
		total += remainder * pow(10, i-1);
	}

	// Check if the given number is equal to the total (2)
	if (x == total) {
		// If (2) true, return true
		return true;
	}
	else {
		// If (2) false, return false
		return false;
	}
}

int main() {
	int num;

	// Get input from the user
	cout << "Type your number: "; cin >> num;

	// Print out the result
	cout << isPalindrome(num) << endl;



	return 0;
}