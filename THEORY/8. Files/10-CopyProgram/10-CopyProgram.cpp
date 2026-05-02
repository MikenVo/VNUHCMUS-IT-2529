#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
	char* pastename = new char[1001]();
	char* copyname = new char[1001]();
	char text[5] = ".txt";

	cout << "Type the file name that you want to copy: ";
	cin.getline(copyname, 1001); // Get the name of the text file the user wants to copy
	strcat(copyname, text); // Add '.txt' to the name

	cout << "Type the file name where you want to paste: ";
	cin.getline(pastename, 1001); // Get the name of the text file the user wants to paste
	strcat(pastename, text); // Add '.txt' to the name

	ifstream copy(copyname);
	ofstream paste(pastename, ios::app /*Append to the text file*/);

	// Print out "Error" of the text files cannot be opened
	if (!copy.is_open() && !paste.is_open()) {
		cout << "ERROR" << endl;
		return 1;
	}

	char* line = new char[1000001];

	paste << endl; // Add a separate line

	while (!copy.eof()) { // Copy each line from the "copy" text file to the "paste" text file. Stop when reach the end of the file
		copy.getline(line, 1000001);
		paste << line << endl;
	}

	delete[] pastename;
	delete[] copyname;
	delete[] line;

	copy.close();
	paste.close();
	return 0;
}