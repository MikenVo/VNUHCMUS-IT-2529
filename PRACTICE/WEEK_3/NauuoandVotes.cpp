#include <iostream>

using namespace std;

int main() {
	int x = 0, y = 0, z = 0;
	bool upvote = false, downvote = false, equal = false;

	cin >> x >> y >> z;

	if (x >= y) {
		if (z != 0) {
			if (x + z > y) {
				upvote = true;
			}
			else if (x + z == y) {
				equal = true;
			}
			
			if (y + z > x) {
				downvote = true;
			}
			else if (y + z == x) {
				equal = true;
			}
		}
		else {
			if (x == y) {
				cout << 0 << endl;
			}
			else {
				cout << "+" << endl;
			}
		}
	}
	else if (y >= x) {
		if (z != 0) {
			if (x + z > y) {
				upvote = true;
			}
			else if (x + z == y) {
				equal = true;
			}

			if (y + z > x) {
				downvote = true;
			}
			else if (y + z == x) {
				equal = true;
			}
		}
		else {
			if (x == y) {
				cout << 0 << endl;
			}
			else {
				cout << "-" << endl;
			}
		}
	}
	else {
		cout << "-" << endl;
	}

	if (upvote && downvote && equal || upvote && downvote || upvote && equal || downvote && equal) {
		cout << "?" << endl;
	}
	else if (upvote) {
		cout << "+" << endl;
	}
	else if (downvote) {
		cout << "-" << endl;
	}
	else if (equal) {
		cout << "0" << endl;
	}

	return 0;
}