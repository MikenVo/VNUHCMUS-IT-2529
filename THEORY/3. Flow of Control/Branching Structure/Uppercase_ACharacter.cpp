#include <iostream>

using namespace std;

int main() {
	char character;

	cout << "Type a character: "; cin >> character;

	if (97 <= character && character <= 122) {
		character = character - 32;
		cout << character << endl;
	}
	else if (60 <= character && character <= 90) {
		cout << character << endl;
	}
	else {
		cout << "ERROR" << endl;
	}

	return 0;
}