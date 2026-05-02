#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream output;
	output.open("output.txt");

	if (output) {
		int num;
		for (int i = 0; i < 3; i++) {
			cin >> num;
			output << num << endl;
		}
	}
	else {
		cout << "ERROR" << endl;
	}

	output.close();
	return 0;
}