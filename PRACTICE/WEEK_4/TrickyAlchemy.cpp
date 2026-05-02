#include <iostream>

using namespace std;

int main() {
	long long current_yellow_crystal, current_blue_crystal;
	long long yellow_ball, green_ball, blue_ball;

	cin >> current_yellow_crystal >> current_blue_crystal;
	cin >> yellow_ball >> green_ball >> blue_ball;

	long long tycry = 0, tbcry = 0;

	if (yellow_ball > 0) {
		tycry += yellow_ball * 2;
	}

	if (green_ball > 0) {
		tycry += green_ball;
		tbcry += green_ball;
	}

	if (blue_ball > 0) {
		tbcry += blue_ball * 3;
	}

	

	if (current_yellow_crystal >= tycry && current_blue_crystal >= tbcry) {
		cout << 0 << endl;
	}
	else if (current_yellow_crystal >= tycry && current_blue_crystal < tbcry) {
		cout << 0 + tbcry - current_blue_crystal << endl;
	}
	else if (current_yellow_crystal < tycry && current_blue_crystal >= tbcry) {
		cout << tycry - current_yellow_crystal + 0 << endl;
	}
	else {
		long long needed_yellow = tycry - current_yellow_crystal, needed_blue = tbcry - current_blue_crystal;
		long long result = needed_yellow + needed_blue;

		cout << result << endl;
	}

	return 0;
}