#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main() {
	char name[1000];
	cout << "Type your string: "; cin.getline(name, 1000);

	for (int i = 0; i < strlen(name); i++) {
		if (isspace(name[i])) {
			for (int j = i; j < strlen(name); j++) {
				name[j] = name[j + 1];
			}
		}
	}

	cout << "Removed space: " << name << endl;

	return 0;
}