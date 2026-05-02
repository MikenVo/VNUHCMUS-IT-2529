#include <iostream> // Add iostream library for easier I/O

using namespace std;

int main() {
    // Define an integer variable "year" and an integer variable "today_year" assigned with today year
    int year;
    int today_year = 2025;

    // Initialize an infinite loop
    while (true) {
        // Ask the user to prompt his/her birth year
        cout << "Type your birth year: "; cin >> year;

        // Check if year is greater than or equal to 0
        if (year >= 0) {
            // If true, print out the answer of (today_year - year)
            cout << "Your age: " << today_year - year << endl;
            break; // Break out the infinite loop
        }
        else {
            // If false, print out "Error"
            cout << "Error" << endl;
            continue; // Continue the infinite loop
        }
    }

    return 0;
}
