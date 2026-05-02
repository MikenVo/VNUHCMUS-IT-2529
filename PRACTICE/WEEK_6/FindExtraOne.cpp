#include <iostream>

using namespace std;

int main() {
	int numofc; cin >> numofc;
	int negx = 0, posx = 0;

	for (int i = 0; i < numofc; i++) {
		int x; int y;
		cin >> x >> y;

		if (x > 0) {
			posx++;
		}
		else if (x < 0) {
			negx++;
		}
	}

	if (negx == 0 && posx == 0) {
		cout << "No" << endl;
	}
	else if (negx == 1 && posx == 1) {
		cout << "Yes" << endl;
	}
	else if ((posx > negx && negx <= 1) || (negx > posx && posx <= 1)) {
		cout << "Yes" << endl;
	}
	else if (posx == negx && posx > 1 && negx > 1) {
		cout << "No" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}