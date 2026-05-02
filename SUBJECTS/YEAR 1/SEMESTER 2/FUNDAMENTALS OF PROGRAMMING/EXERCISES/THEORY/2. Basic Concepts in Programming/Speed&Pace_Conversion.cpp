#include <iostream>

using namespace std;

int main() {
	double speed;
	double pace;

	while (true) {
		cout << "Type your speed (km/h) and pace (min/km): "; cin >> speed >> pace;
		if (speed <= 0 && pace <= 0) {
			cout << "ERROR" << endl;
			continue;
		}
		else {
			cout << "speed -> pace: pace = 60 / speed = " << 60 / speed << " min/km. " << endl << "pace -> speed: speed = 60 / pace = " << 60 / pace << " km/h." << endl;
			break;
		}
	}
	return 0;
}