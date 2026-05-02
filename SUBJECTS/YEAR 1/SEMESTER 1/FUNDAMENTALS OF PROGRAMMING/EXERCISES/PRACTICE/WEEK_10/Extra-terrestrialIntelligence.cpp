#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int numberofdays;

	ifstream readFile("input.txt");
	ofstream writeFile("output.txt");

	if (!readFile) {
		cout << "ERROR" << endl;
	}

	readFile >> numberofdays;

	readFile.ignore();

	char* message = new char[numberofdays + 1];
	readFile.getline(message, numberofdays + 1);

	int firstindex = 0, secondindex = 0;
	bool isIntelligence = false; bool foundFirst = false;

	// Find the first index
	for (int i = 0; i < numberofdays; i++) {
		if (message[i] == '1') {
			if (i == numberofdays - 1) {
				writeFile << "NO" << endl;
				return 0;
			}

			if (foundFirst) {
				secondindex = i;
				break;
			}

			firstindex = i;
			foundFirst = true;
		}
	}

	if (!foundFirst) { // If there is no 1s, print out NO
		writeFile << "NO" << endl;
		return 0;
	}

	int distance = 0;
	distance = secondindex - firstindex;
	firstindex = secondindex;
	secondindex = 0;

	// Find the second index and measure the system
	for (int i = firstindex + 1; i < numberofdays; i++) {
		if (message[i] == '1') {
			secondindex = i;

			if (secondindex - firstindex == distance) {
				isIntelligence = true;

				firstindex = secondindex;
				secondindex = 0;
			}
			else {
				isIntelligence = false;
				break;
			}
		}
	}

	if (isIntelligence) {
		writeFile << "YES" << endl;
	}
	else {
		writeFile << "NO" << endl;
	}

	readFile.close();
	writeFile.close();
	delete[] message;
	return 0;
}