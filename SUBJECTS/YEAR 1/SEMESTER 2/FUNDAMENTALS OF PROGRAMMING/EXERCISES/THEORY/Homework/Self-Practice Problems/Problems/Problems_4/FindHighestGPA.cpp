#include <fstream>
#include <iostream>
#include <string>
#include <sstream>  // Needed for stringstream
#include <iomanip>

using namespace std;

int main() {
	ifstream inFile("input.txt");

	if (!inFile) {
		cout << "Error opening file!" << endl;
		return 1;
	}

	double result_score = -1.0;
	string line;
	string name;
	double math_score, literature_score, english_score;

	// Read each line
	while (getline(inFile, line)) {


		stringstream ss(line);  // Turn the line into a stream

		// Read name (until comma)
		getline(ss, name, ',');

		// Read the scores as strings first, then convert
		string math_str, lit_str, eng_str;
		getline(ss, math_str, ',');
		getline(ss, lit_str, ',');
		getline(ss, eng_str, ',');  // last one also uses ',' but it's fine

		// Convert strings to double
		math_score = stod(math_str);
		literature_score = stod(lit_str);
		english_score = stod(eng_str);

		double cur_result = (math_score + literature_score + english_score) / 3.0;

		if (cur_result >= result_score) {
			result_score = cur_result;
		}
	}
	inFile.close();

	ifstream inFile2("input.txt");
	ofstream outFile("output.txt");

	if (!inFile2) {
		return 1;
	}

	outFile << fixed << setprecision(1);

	while (getline(inFile2, line)) {
		stringstream ss(line);  // Turn the line into a stream

		// Read name (until comma)
		getline(ss, name, ',');

		// Read the scores as strings first, then convert
		string math_str, lit_str, eng_str;
		getline(ss, math_str, ',');
		getline(ss, lit_str, ',');
		getline(ss, eng_str, ',');  // last one also uses ',' but it's fine

		// Convert strings to double
		math_score = stod(math_str);
		literature_score = stod(lit_str);
		english_score = stod(eng_str);

		double cur_result = (math_score + literature_score + english_score) / 3.0;

		if (cur_result >= result_score) {
			outFile << name << "," << cur_result << endl;
		}
	}

	inFile2.close();
	outFile.close();
	return 0;
}