/* Problem: Write a program to count duplicated words in a file and store the result to another file
*  Test case:
*  InputFile -> Hello World, my name is Hello
*  OuputFile -> Hello: 2 | World: 1 | my: 1 | name: 1 | is: 1
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct wordProp {
	string word;
	int count;
};

int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");

	// This problem is similar to 7-WordCount, the idea to solve it is the same (You should check it to understand my concept)

	wordProp *wordcount = new wordProp[1000000](); // Initialize a wordProp array

	string word /* Get the word */; bool start = false /* Initialize the counter */, found = false;
	int lastword = 1;

	if (!input || !output) {
		cout << "ERROR" << endl;
		return 1;
	}

	// Get individual words
	while (input >> word) {
		for (int i = 0; i < word.length(); i++) {
			if (word[i] == ',' || word[i] == '.') { // Erase the punctation in the word
				word.erase(word.begin() + i);
			}
		}

		// Start the counter when encounter the first word
		if (!start) {
			wordcount[0].word = word; // Assign the first word to the first slot
			wordcount[0].count = 1;
			start = true;
		}
		else {
			// Check if the word has appeared before in the array
			for (int i = 0; i < lastword; i++) {
				if (wordcount[i].word == word) { // If found, increase the count and get the next word
					wordcount[i].count++;
					found = true;
				}
			}

			if (!found) { // If not found, assign the new word to the latest slot
				wordcount[lastword].word = word;
				wordcount[lastword].count++;
				lastword++; // Increase the word count
				found = false;
			}
		}
	}

	// Print out the word count to the output text file
	for (int i = 0; i < lastword; i++) {
		output << wordcount[i].word << ": " << wordcount[i].count << endl;
	}

	input.close();
	output.close();
	return 0;
}