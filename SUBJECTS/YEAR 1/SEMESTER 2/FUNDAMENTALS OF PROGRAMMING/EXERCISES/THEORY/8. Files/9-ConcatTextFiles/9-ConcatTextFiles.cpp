#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream text1("text1.txt"); // Read the first text file
	ifstream text2("text2.txt"); // Read the second text file
	ofstream output("output.txt"); // Store the content of both text files

	// Check if the two main files are open correctly
	if (!text1.is_open() && !text2.is_open()) {
		cout << "ERROR" << endl;
		return 1;
	}

	string line; // Store each line in one text file

	// Write the content of the first text file to the output file
	while (getline(text1, line)) {
		output << line << endl;
	}

	// Write the content of the second text file to the output file
	while (getline(text2, line)) {
		output << line << endl;
	}

	text1.close();
	text2.close();
	output.close();
	return 0;
}