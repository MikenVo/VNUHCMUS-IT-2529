#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

// Function to check if the character is a alphabetic character
bool isAlpha(char c) {
	if ((('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z'))) {
		return true;
	}
	return false;
}

string reverseWords(string s) {
	// H e l l o   W o r l d
	// 0 1 2 3 4 5 6 7 8 9 10

	int num = s.length(); // Get the length of the string

	// Reverse the whole string
	for (int i = 0, j = num - 1; i < (num - 1) / 2, j >(num - 1) / 2; i++, j--) { // Stop when i and j reach the middle of the string
		char temp = s[i];
		s[i] = s[i + (j - i)];
		s[j] = temp;
	}

	int start = 0, end = 0, numberofwords = 0;
	while (end < num) { // Stop when i reaches to the end to the string
		while (isAlpha(s[end])) { // Count the characters in one word
			numberofwords++;
			end++;
		}

		numberofwords--;

		// Reverse the word
		for (int k = start, m = numberofwords; k < (end + start)/2; k++) {
			char temp = s[k];
			s[k] = s[k + m];
			s[k + m] = temp;
			m -= 2;
		}

		end = end + 1; // Modify the i to skip the whitespace
		start = end;
		numberofwords = 0;
	}

	return s;
}

int main() {
	string s; getline(cin, s);
	cout << reverseWords(s) << endl;

	return 0;
}