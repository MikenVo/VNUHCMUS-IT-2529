#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// If s[i] is a vowel, check if it is even
// If s[i] is an odd number, check if it is not a wovel
// Else, pass

// 4b3a
// Check 3, a

int convert(char num) {
	int newnum = num - '0';
	return newnum;
}

bool isVowel(char checkchar) {
	if (checkchar == 'a' || checkchar == 'e' || checkchar == 'i' || checkchar == 'o' || checkchar == 'u') {
		return true;
	}
	return false;
}

int main() {
	char s[51];
	cin.getline(s, 51);
	int check = 0;

	for (int i = 0; i < strlen(s); i++) {
		if (isVowel(s[i])) {
			check++;
		}

		if ((s[i] >= '0' && s[i] <= '9') && (convert(s[i]) % 2 != 0)) {
			check++;
		}
	}

	cout << check << endl;

	return 0;
}
