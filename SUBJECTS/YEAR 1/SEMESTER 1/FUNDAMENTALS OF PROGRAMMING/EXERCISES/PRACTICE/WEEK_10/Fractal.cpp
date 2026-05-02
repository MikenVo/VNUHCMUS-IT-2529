#include <fstream>

using namespace std;

int power(int base, int exp) {
	int result = 1;
	for (int i = 0; i < exp; i++) {
		result *= base;
	}
	return result;
}

void draw(char** result, char** model, int n, int x, int y, int lev) {
	// If there is no step, stop the function
	if (lev == 0) {
		return;
	}

	// Calculate the size every recursion
	int sub = power(n, lev - 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int nx = x + i * sub;
			int ny = y + j * sub;

			if (model[i][j] == '*') {
				for (int row = 0; row < sub; row++) {
					for (int col = 0; col < sub; col++) {
						result[nx + row][ny + col] = '*';
					}
				}
			}
			else {
				// Recursion
				draw(result, model, n, nx, ny, lev - 1);
			}
		}
	}
}

int main() {
	ifstream readFile("input.txt");
	ofstream writeFile("output.txt");

	int n, k; readFile >> n >> k; // Read the n and number of steps
	readFile.ignore();

	char buffer[4];

	// Allocate memory to a 2D array to read the pattern
	char** model = new char* [n];
	for (int i = 0; i < n; i++) {
		model[i] = new char[n + 1];

		readFile.getline(buffer, 4);

		for (int j = 0; j < n; j++) {
			model[i][j] = buffer[j];
		}
		model[i][n] = '\0';
	}

	int size = power(n, k);

	char** result = new char* [size];
	for (int i = 0; i < size; i++) {
		result[i] = new char[size];
		for (int j = 0; j < size; j++) { // Make the whole canvas "white"
			result[i][j] = '.';
		}
	}

	draw(result, model, n, 0, 0, k);

	// Print the result
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			writeFile << result[row][col];
		}
		writeFile << endl;
	}

	// Memory deallocation
	for (int i = 0; i < n; i++) {
		delete[] model[i];
	}
	delete[] model;

	for (int i = 0; i < size; i++) {
		delete[] result[i];
	}
	delete[] result;

	// Close files
	readFile.close();
	writeFile.close();

	return 0;
}