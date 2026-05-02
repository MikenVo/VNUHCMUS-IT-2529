// Task: Student Records
// - Create a file students.file
// - Write 5 student records (name and score)
// - Read the file and compute average score
// - Display student with highest score

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cctype>

using namespace std;

// To replace the '-' with ' '
char* replacespaces(char* name) {
	int len = strlen(name);
	for (int i = 0; i < len; i++) {
		if (name[i] == '-') {
			name[i] = ' ';
		}
	}

	return name;
}

int main() {
	ifstream read("students.txt", ios::in);

	// Check if 'students.txt' is available
	if (!read.is_open()) {
		cout << "Error: Cannot open file" << endl;
		return 1;
	}

	char* name = new char[1000001]; // Store the student's name
	float math_score, literature_score, english_score; // Store the student's scores (Math, Literature, English)

	float average = 0; // Store the average score

	// Instructions
	cout << "Please read these information before continuing: " << endl;
	cout << "- The students' information must be inputted inside 'students.txt' file." << endl;
	cout << "- Enter students' basic information: Full name, Math score, Literature score and English score." << endl;
	cout << "+ + Please replace the spaces in the full name with '-'. E.g. Nguyen Van A -> Nguyen-Van-A." << endl;
	cout << "+ + The scores must be integers or floats. The order of the scores is matter (Math -> Literature -> English)" << endl;

	cout << endl;

	// I added this to make the program functional and cohesive
	// The user may not know which file to input or they will input the wrong order
	char ans;
	cout << "After inputting the information, only type 'Y' when criteria are satisfied or you are ready: ";
	cin >> ans;

	if (tolower(ans) == 'y') {
		cout << endl;
		cout << "--- Student Information ---" << endl;
		while (read >> name >> math_score >> literature_score >> english_score) {
			cout << "---!---" << endl;

			average = (math_score + literature_score + english_score) / 3.0f; // Calculate the average score
			cout << "Full name: " << replacespaces(name) << endl; // Print out the "fixed" name. E.g. Nguyen-Van-A -> Nguyen Van A

			// Print out the scores
			cout << "- Math score: " << math_score << endl;
			cout << "- literature score: " << literature_score << endl;
			cout << "- English score: " << english_score << endl;
			cout << "**Average score**: " << setprecision(2) << average << endl;
		}
	}
	else {
		cout << "Invalid input, please rerun the program to restart" << endl;
		return 1;
	}

	delete[] name;

	read.close();

	return 0;
}