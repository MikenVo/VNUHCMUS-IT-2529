#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string message;
	ofstream output("output.txt");

	if (output) {
		// Set an infinite loop to record all the message inputted by the user until they type "Message out"
		while (true) {
			getline(cin, message); // Get the message
			if (message == "Message out") {
				output << message; // Print the message to the output text file and break out the loop
				break;
			}
			output << message << endl; // Print the message to the output text file
		}
	}
	else {
		cout << "ERROR" << endl;
		return 1;
	}

	output.close();
	return 0;
}