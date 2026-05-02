#include <iostream>

using namespace std;

bool isLeap(int y) {
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int y; cin >> y;
	int dayshift = 0;
	int isleap = false;

	if (isLeap(y)) { isleap = true; }

	while (true) {
		int isSamekind = false;

		y++;
		if (isLeap(y)) {
			dayshift += 2;
			isSamekind = true;
		}
		else {
			dayshift++;
			isSamekind = false;
		}

		if (dayshift % 7 == 0 && isleap == isSamekind) {
			cout << y << endl;
			break;
		}
		else if (dayshift % 7 == 0 && isleap != isSamekind) {
			dayshift = 0;
		}
	}

	return 0;
}