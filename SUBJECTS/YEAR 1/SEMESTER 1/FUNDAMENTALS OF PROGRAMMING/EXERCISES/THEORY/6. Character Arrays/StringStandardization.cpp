#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char str[1000];

	cout << "Type your string: "; cin.getline(str, 1000);

	int n = 0;

	while (n < strlen(str)) {
		if (str[0] == 32) {
			for (int i = 0; i < strlen(str); i++) {
				str[i] = str[i + 1];
			} 
			n--;
		}
		else if (str[n] == 32 && str[n+1] == 32) {
			for (int i = n + 1; i < strlen(str); i++) {
				str[i] = str[i+1];
			}
			n--;
		}
		n++;
	}

	cout << "Answer: " << str << endl;

	return 0;
}