#include <iostream>
#include <cstring>

using namespace std;

int LenCheck(char arr[]) {
	return strlen(arr);
}

int main() {
	int counter = 0;
	char str[1000]; char newstr[100];

	cout << "Remember to write out the words for more accuracy. E.g. Don't -> Do not" << endl;
	cout << "Type your string: "; cin.getline(str, 1000);

	if (str[0] == ' ') {
		for (int i = 0; i < strlen(str); i++) {
			str[i] = str[i + 1];
		}
	}

	int last = 0, after = 0;

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 32 || str[i] == '\0') {
			last = LenCheck(newstr);
			counter = 0;
			break;
		}
		else {
			newstr[counter] = str[i];
			counter++;
		}
	}

	for (int i = last + 1; i < strlen(str); i++) {
		if (str[i] == 32 || str[i] == '\0') {
			if (after > last) {
				last = after;
				for (int j = i - after; j < after; j++) {
					newstr[counter] = str[j];
					counter++;
				}
			}
			else {
				after = 0;
			}
		}
		else {
			after++;
		}
	}

	cout << "Answer: " << newstr << " - " << last << endl;

	return 0;
}