#include <iostream>
#include <cstring>

using namespace std;

// The problem tells us to print out the correct format of a string.
// For example: hello,world -> hello, world for all punctuation except " " and ' '.

// Step 1: Erase unnecessary spaces
// - Check if there is a space after a space.
// Step 2: Add necessary spaces to punctuations (except " " and ' ')
// Step 3: Handle the " " and ' '

// Puncatuations:
/*
* !
* ,
* .
* ;
* :
* ?
* ""
* ''
*/

// Hello,world -> Hello, World
//     Hello    World -> Hello World

bool IsChar(char c) {
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
		return true;
	}
	else {
		return false;
	}
}

bool IsPunc(char c) {
	if (c == '!' || c == ',' || c == '.' || c == ';' || c == ':' || c == '?') {
		return true;
	}
	else {
		return false;
	}
}

bool IsQuo(char c) {
	if (c == '\'' || c == '\"') {
		return true;
	}
	else {
		return false;
	}
}

// Xóa khoảng cách
// - 1 space sau 1 space.
// - 1 space trước 1 punc.
// - 1 space ở vị trí index 0. <-
// Format punctations

// Tạo mảng mới
// Cho vòng lặp
// - Gặp chữ -> copy qua
// - Format -> copy qua

// Vấn đề index

// Hello,world
// H e l l o, world

int main() {
	char s[10001];

	cin.getline(s, 10001);

	int i = 0;

	while (i < strlen(s)) {
		if (IsChar(s[i])) {
			i++;
		}
		else if (isspace(s[i]) && isspace(s[i + 1])) {
			for (int j = i; j <= strlen(s) + 1; j++) {
				s[j] = s[j + 1];
			}
			i--;
		}
		else if (IsPunc(s[i]) && isspace(s[i - 1])) {
			for (int j = i - 1; j <= strlen(s) + 1; j++) {
				s[j] = s[j + 1];
			}
		}
		else {
			i++;
		}
	}

	std::cout << s << endl;

	return 0;
}