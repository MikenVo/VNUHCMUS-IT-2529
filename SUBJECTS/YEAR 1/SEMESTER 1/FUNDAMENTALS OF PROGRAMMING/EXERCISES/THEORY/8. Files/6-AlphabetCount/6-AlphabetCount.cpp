#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");

	// We will take each word and convert each character from upper to lower
	// Iterate through each charater to count the alphabetic character

	// Example: Hello World
	// - Hello -> hello
	// - hello -> h e l l o (h: 1, e: 1, l: 2, o: 1)

	// - World -> world
	// - world -> w o r l d (w: 1, o: 2, r: 1, l: 3, d: 1)

	// h: 1, e: 1, l: 3, o: 2, w: 1, r: 1, d: 1

	if (input && output) {
		string word;
		int charcount[26] = { 0 }; // Initialize an array to keep track the number of each character
		while (!input.eof()) {
			getline(input, word); // Get a line

			// Iterate through each character
			for (int i = 0; i < word.length(); i++) {
				if (isupper(word[i])) {
					word[i] = tolower(word[i]); // Convert upper characters to lower charaters
				}



				// Characters can be represented as numbers, we know the exact number using ASCII
				// Example: 'a' -> 97, 'b' -> '98', 'c' -> '99'
				
				// Therefore, we can use the difference between the current character and 'a' as the indexes
				// Example: "hello" -> h e l l o
				// - 'h' (104) - 'a' (97) = 7 => charcount[7] = 1
				// - 'e' (101) - 'a' (97) = 4 => charcount[4] = 1
				// - 'l' (108) - 'a' (97) = 11 => charcount[11] = 1
				// - 'l' (108) - 'a' (97) = 11 => charcount[11] = 2
				// - 'o' (111) - 'a' (97) = 14 => charcount[14] = 1
				charcount[word[i] - 'a']++;
			}
		}

		// Print the character count to the output text file
		for (int i = 0; i < 26; i++) {
			output << (char)(i + 'a') /* Convert int to char. E.g. i = 0 -> i + 'a' = 97 -> 'a' */ << ": " << charcount[i] << endl;
		}
	}
	else {
		cout << "ERROR" << endl;
		return 1;
	}

	input.close();
	output.close();
	return 0;
}