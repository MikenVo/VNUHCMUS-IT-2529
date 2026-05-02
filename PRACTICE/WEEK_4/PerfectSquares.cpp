#include <iostream>
#include <cmath>

using namespace std;

bool isPSquare(int num) {
	int can = sqrt(num);
	
	if (num >= 0) {
		if (pow(can,2) == num) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	int numofe = 0;
	int num = 0;
	int can = -pow(10,6);
	cin >> numofe;

	for (int i = 0; i < numofe; i++) {
		cin >> num;
		if (num >= 0) {
			if (num >= can && !isPSquare(num)) {
				can = num;
			}
		}
		else {
			if (num >= can) {
				can = num;
			}
		}
		
	}

	cout << can << endl;

	return 0;
}