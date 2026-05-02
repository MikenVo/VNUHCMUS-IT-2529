#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
	ifstream readFile("input.txt");
	ofstream writeFile("output.txt");

	if (!readFile) { writeFile << "ERROR" << endl; return 1; }

	char* entrance = new char[6];

	readFile.getline(entrance, 6);
	if (strcmp(entrance, "front") == 0) {
		entrance[5] = '\0';
	}
	else if (strcmp(entrance, "back") == 0) {
		entrance[4] = '\0';
	}
	else {
		writeFile << "ERROR" << endl;
		return 1;
	}

	int rail;
	readFile >> rail;

	if (strcmp(entrance, "front") == 0 && rail == 1) { writeFile << "L" << endl; }
	else if (strcmp(entrance, "front") == 0 && rail == 2) { writeFile << "R" << endl; }
	else if (strcmp(entrance, "back") == 0 && rail == 1) { writeFile << "R" << endl; }
	else if (strcmp(entrance, "back") == 0 && rail == 2) { writeFile << "L" << endl; }
	else { writeFile << "ERROR" << endl; return 1; }

	delete[] entrance;
	readFile.close();
	writeFile.close();
	return 0;
}