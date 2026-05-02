#include <iostream>

using namespace std;

int main() {
	float score;

	while (true) {
		cout << "Type the score: "; cin >> score;

		if (score >= 0.00f) {
			if (score < 5.00f) {
				cout << "Poor" << endl;
				break;
			}
			else if (5.00f <= score && score < 7.00f) {
				cout << "Fair" << endl;
				break;
			}
			else if (7.00f <= score && score < 8.00f) {
				cout << "Good" << endl;
				break;
			}
			else if (8.00f <= score && score < 9.00f) {
				cout << "Very good" << endl;
				break;
			}
			else if (9.00f <= score && score <= 10.00f) {
				cout << "Excellent" << endl;
				break;
			}
			else {
				cout << "Invalid" << endl;
				break;
			}
		}
		else {
			cout << "ERROR" << endl;
			continue;
		}
	}

	return 0;
}