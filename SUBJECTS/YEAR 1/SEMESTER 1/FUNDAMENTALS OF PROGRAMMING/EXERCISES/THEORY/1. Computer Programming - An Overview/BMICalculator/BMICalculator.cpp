#include <iostream> // Add iostream library for an easier I/O

using namespace std;

int main() {
    // Define two float variables "weight" and "height"
    float weight, height;

    // Initialize an infinite loop
    while (true) {
        // Ask the user to prompt their weight in kg and height in m
        cout << "Type your weight (kg) and height (m): "; cin >> weight >> height;

        // Check if "weight" is greater than 0 and "height" is greater than 0.1
        if (weight > 0 && height > 0.1) {
            // If true, print the answer of (weight/(height*height))
            cout << weight/(height*height) << endl;
            break; // Break out the infinite loop
        }
        else {
            // If false, print "ERROR"
            cout << "ERROR" << endl;
            continue; // Continue the infinite loop
        }
    }

    return 0;
}