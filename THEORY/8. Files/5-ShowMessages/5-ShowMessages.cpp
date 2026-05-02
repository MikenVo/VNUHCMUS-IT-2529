#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream input("input.txt");
	string message;

	// We need to get the line and output the line on the terminal
	if (input) {
		while (!input.eof()) {
			getline(input, message); // Get the message from the input text file
			cout << message << endl; // Print out the message
		}
	}
	else {
		cout << "ERROR" << endl;
		return 1;
	}

	input.close();
	return 0;
}