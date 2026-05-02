// Problem: Write C/C++ program to find and replace all as follow:
// - Enter a sentence of words S.
// - Enter word to find F, and replacing word R.
// - Find and replace all F is S with R.
// - Print the result sentence.
// Input format:
// - Enter a sentence: the good, the bad, the ugly
// - Enter find word: the
// - Enter replacing word: (a very)
// Output format: (a very) good, (a very) bad, (a very) ugly

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	// Initialization
	char* mainstr = new char[1000001](); // Store the main string
	char* targetstr = new char[1000001](); // Store the string the user wants to find and replace
	char* replacestr = new char[1000001](); // Store the string the user wants to replace
	char* resultstr = new char[1000001](); // Store the final string after replacement

	// Input
	cin.getline(mainstr, 1000001); // Input the main string

	while (true) {
		cin.getline(targetstr, 1000001); // Input the target string
		if (strlen(targetstr) > strlen(mainstr)) { // If the target string is longer than main string
			cout << "Invalid input, the length of the target string should be shorter or equal to the main string!" << endl;
			continue; // Tell the user to input again
		}
		else {
			break;
		}
	}

	cin.getline(replacestr, 1000001); // Input the replace string

	// Second initialization
	char* mainstrp = mainstr; // Initialize a pointer pointing at the first element of the main string 
	char* resultstrp = resultstr; // Initialize a pointer pointing at the first element of the result string
	char* found = strstr(mainstr, targetstr); // Find the first occurrence of the target string in the main string

	if (found == nullptr) { // If the algorithm cannot find the target string, exit the program
		cout << "Invalid" << endl;
		return 1;
	}

	while (found != nullptr) { // Loop until the algorithm cannot find any target string in the main string
		found = strstr(mainstrp, targetstr); // Recheck if there are still target strings available

		// Copy the characters from the main string to final string until reach the target string
		while (mainstrp != found) {
			*(resultstrp++) = *(mainstrp++);

			// If the main string pointer reachs the end of the main string, break out the loop
			if (*(mainstrp) == '\0') {
				break;
			}
		}

		// Replace the target string with the replace string
		if (*(mainstrp) != '\0') {
			strcat(resultstr, replacestr);
			resultstrp = resultstr;
			resultstrp += strlen(resultstr);
			mainstrp += strlen(targetstr);
		}
	}

	cout << resultstr << endl; // Print out the final string

	delete[] mainstr;
	delete[] targetstr;
	delete[] replacestr;
	delete[] resultstr;

	return 0;
}