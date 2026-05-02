#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char words[1000]; int nwords = 0;

	cout << "Type your string: "; cin.getline(words, 1000);

	for (int i = 0; i < strlen(words); i++) {
		if (isspace(words[i]) && i != 0) {
			nwords++;
		}
	}

	cout << "Number of words: " << nwords + 1 << endl;

	return 0;
}