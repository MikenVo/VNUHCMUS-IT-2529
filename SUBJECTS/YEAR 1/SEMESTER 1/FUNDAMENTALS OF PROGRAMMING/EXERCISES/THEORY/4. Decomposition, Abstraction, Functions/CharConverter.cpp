#include <iostream>

using namespace std;

int main() {
	char result = 0;
	char character; cin >> character;
	if (65 <= character && character <= 90) {
		result = character | 32;
	}
	else if (97 <= character && character <= 122) {
		result = character ^ 32;
	}

	cout << result << endl;

	return 0;
}