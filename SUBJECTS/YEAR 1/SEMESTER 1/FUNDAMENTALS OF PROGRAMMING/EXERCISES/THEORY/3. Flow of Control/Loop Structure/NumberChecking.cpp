// Done

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string checksym(int n) {
	unsigned int store = n; // Store a copy of the number n
	unsigned int length = 0; // Store number of digits in the number n
	unsigned int remainder = 0; // Store the remainder when modulo-ing
	unsigned int total = 0; // Store the total of the remainder * 10s
	
	length = to_string(store).length();

	for (int i = length; i > 0; i--) {
		remainder = store % 10;
		total += remainder * pow(10,(i-1));
		store /= 10;
	}

	if (total == n) {
		return "Yes";
	}
	else {
		return "No";
	}
}

string checksqu(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				continue;
			}
			else {
				if (i * j == n && i == j) {
					return "Yes";
				}
			}
		}
	}
	return "No";
}

string checkpri(int n) {
	bool IsPrime = true;

	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			IsPrime = false;
			break;
		}
	}

	if (IsPrime) {
		return "Yes";
	}
	else {
		return "No";
	}
}

pair<int, int> findlarsma(int n) {
	int remainder = 0;
	int largest, smallest;
	int store = n;

	remainder = store % 10;
	largest = remainder; smallest = remainder;

	for (int i = to_string(n).length(); i > 0; i--) {
		remainder = store % 10;
		store /= 10;
		

		if (remainder > largest) {
			largest = remainder;
		}

		if (remainder < smallest) {
			smallest = remainder;
		}
	}

	return { largest, smallest };
}

string checkasdes(int n) {
	int digits = 0;
	bool ascending = false, descending = false;

	for (int i = n; i > 0; digits++) {
		i /= 10;
	}

	int lis[digits];
	int j = 0;

	for (int i = digits; i >= 0; i--) {
		lis[j] = n % 10;
		n /= 10;
		j++;
	}

	j = 0;

	if (digits == 1) {
		return "Not in an specific order";
	}
	else {
		while (j < digits - 1) {
			if (lis[j] >= lis[j + 1] && j+1 <= digits) {
				if (lis[j] == 0 && lis[j + 1] == 0 && lis[j + 1] < lis[j + 2] && j + 2 <= digits) {
					return "Not in an specific order";
				}
				else if (lis[j+1] < lis[j+2] && j+2 <= digits) {
					descending = true;
					ascending = false;
				}
				else {
					ascending = true;
				}
			}
			else if (lis[j] <= lis[j+1] && j+1 <= digits) {
				if (lis[j] > lis[j + 1] && j+1 <= digits) {
					return "Not in an specific order";
				}
				else {
					descending = true;
				}
			}
			else {
				return "Not in an specific order";
			}
			j++;
		}
	}

	if (ascending && descending) {
		return "Not in an specific order";
	}
	else if (ascending) {
		return "Ascending order";
	}
	else if (descending) {
		return "Descending order";
	}
}

int main() {
	unsigned int n;

	cout << "You will input an unsigned integer n (n > 0)" << "\n" << "The number will be checked through these questions: " << endl;
	cout
		<< "1. Is it a symmetrical number?\n"
		<< "2. Is it a square number?\n"
		<< "3. Is it a prime number ? \n"
		<< "4. What are the largest and smalles digits in the number?\n"
		<< "5. The digits in the number are an ascending order or descending order or not?"
		<< endl;

	cout << "\n" << "Type your number: "; cin >> n;

	cout << "Answer to Q1: " << checksym(n) << endl;
	cout << "Answer to Q2: " << checksqu(n) << endl;
	cout << "Answer to Q3: " << checkpri(n) << endl;
	cout << "Answer to Q4: " << "Max: " << findlarsma(n).first << " " << "Min: " << findlarsma(n).second << endl;
	cout << "Asnwer to Q5: " << checkasdes(n) << endl;

	return 0;
}