/* Problem: Write a program to count words of a file and store the result to another file */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// I use struct to manage words
struct words {
	string word;
	int count;
};

int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");

	if (!input && !output) {
		cout << "ERROR" << endl;
		return 1;
	}

	words* wordcount = new words[1000000]; // Initialize a words array
	int lastelement = 1; // Use to keep track the number of distinct words appeared in the line
	string word;
	bool start = false /* To initialize the counter */, found = false; // To mark if the word is found to increase the count of that word

	while (input >> word) {
		if (!start) { // Initialize the counter when encounter the first word
			wordcount[0].word = word;
			wordcount[0].count = 1;
			start = true;
		}
		else {
			// Iterate through the array to check if the word has appeared before
			for (int i = 0; i < lastelement; i++) {
				if (wordcount[i].word == word) {
					wordcount[i].count++; // If found, increase the count
					found = true;
					break;
				}
				else {
					found = false;
				}
			}

			if (!found) { // If the word is not found in the array
				wordcount[lastelement].word = word; // Assign it to a new slot
				wordcount[lastelement].count = 1;
				lastelement++; // Increase the number of distinct words
			}
		}
	}

	// Print out the word count
	for (int i = 0; i < lastelement; i++) {
		output << wordcount[i].word << ": " << wordcount[i].count << endl;
	}

	input.close();
	output.close();
	return 0;
}