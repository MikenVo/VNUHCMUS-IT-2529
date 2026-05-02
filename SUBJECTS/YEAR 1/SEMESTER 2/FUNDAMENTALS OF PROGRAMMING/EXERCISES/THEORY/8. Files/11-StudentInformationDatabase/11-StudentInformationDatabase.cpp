// Write a program to store a list of student information to a file and load them to a screen

#include <iostream>
#include <fstream>
#include <limits>
#include <cstring>

using namespace std;

char* replacespace(char schoolname[]) { // Iterate through the character array to find '-'
	int len = strlen(schoolname);
	for (int i = 0; i < len; i++) {
		if (schoolname[i] == '-') {
			schoolname[i] = ' ';
		}
	}

	return schoolname;
}

void printfile(char name[], char birthdate[], int age, bool isMale, char schoolname[], char classcode[]) {
	cout << endl;
	cout << "--- Student Information ---" << endl;

	char* line = new char[1000000001];

	ifstream read("list.txt");

	// Read information on each line
	while (read >> name >> birthdate >> age >> isMale >> schoolname >> classcode) {
		cout << "---!!!---" << endl;

		cout << "Name: " << replacespace(name) /* Replace '-' with ' ' */ << endl;
		cout << "Birth date: " << birthdate << endl;
		cout << "Age: " << age << endl;
		if (isMale) {
			cout << "Gender: Male" << endl;
		}
		else {
			cout << "Gender: Female" << endl;
		}
		cout << "School: " << replacespace(schoolname) << endl;;
		cout << "Class Code: " << classcode << endl;
	}

	delete[] line;

	read.close();
}

int main() {
	// Student information
	// - Name
	// - Birth date
	// - Age
	// - Gender
	// - School
	// - Class

	const int NAME_SIZE = 101;
	const int BIRTHDATE_SIZE = 11;
	const int SCHOOLNAME_SIZE = 1000001;
	const int CLASSCODE_SIZE = 6;

	char* name = new char[NAME_SIZE]();
	char* birthdate = new char[BIRTHDATE_SIZE](); // Longest: 12/12/9999
	int age;
	bool isMale = false;
	char* schoolname = new char[SCHOOLNAME_SIZE];
	char* classcode = new char[CLASSCODE_SIZE]; // Assume the school has a lot of classes from 00A00 to 99Z99

	ofstream write("list.txt");
	int numofstudents; cin >> numofstudents; // We need to specify the number of students
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < numofstudents; i++) {
		cout << "--------------------" << endl;

		// Ask the user to replace ' ' with '-' to handle easily
		cout << "Student's name (Replace spaces with '-'. E.g. Harry Potter -> Harry-Potter): ";
		cin.getline(name, NAME_SIZE);

		cout << "Student's birth date (DD/MM/YY): ";
		cin >> birthdate;

		cout << "Student's age: ";
		cin >> age;

		cout << "Student's gender (Press 1 for male, 0 for female): ";
		cin >> isMale;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Handle the buffer

		cout << "Student's school (Replace spaces with '-'. E.g. Ho Chi Minh City University of Science -> Ho-Chi-Minh-City-University-of-Science): ";
		cin.getline(schoolname, SCHOOLNAME_SIZE);

		cout << "Student's class: ";
		cin >> classcode;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Handle the buffer

		// Add the information into a text file
		write << name << " " << birthdate << " " << age << " " << isMale << " " << schoolname << " " << classcode << endl;

		cout << endl;
	}

	// Print the student list on the terminal
	printfile(name, birthdate, age, isMale, schoolname, classcode);

	delete[] name;
	delete[] birthdate;
	delete[] schoolname;
	delete[] classcode;

	write.close();
	return 0;
}