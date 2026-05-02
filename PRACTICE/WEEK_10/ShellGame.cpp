#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream readFile("input.txt");
	ofstream writeFile("output.txt");

	int ballIndex;
	readFile >> ballIndex;

	readFile.ignore();

	char* action = new char[4];
	action[3] = '\0';

	int leftIndex, rightIndex;

	while (!readFile.eof()) {
		readFile >> leftIndex >> rightIndex;
		if (leftIndex == ballIndex || rightIndex == ballIndex) {
			if (ballIndex == leftIndex) {
				ballIndex = rightIndex;
			}
			else if (ballIndex != leftIndex) {
				ballIndex = leftIndex;
			}
		}
		else {
			continue;
		}
	}

	writeFile << ballIndex << endl;

	readFile.close();
	writeFile.close();
	delete[] action;
	return 0;
}