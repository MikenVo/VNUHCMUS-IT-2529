#include <iostream>

using namespace std;

int process(int p) {
	int r0 = 0,
		r1 = 0,
		r2 = 0,
		r3 = 0,
		r4 = 0,
		r5 = 0,
		r6 = 0,
		r7 = 0,
		r8 = 0,
		r9 = 0;
	int total = 0;
	char c;

	for (int i = p; i > 0; i--) {
		cin >> c;
		if (c == 'L') {
			if (r0 == 0) {
				r0 = 1;
			}
			else if (r0 == 1 && r1 == 0) {
				r1 = 1;
			}
			else if (r0 == 1 && r1 == 1 && r2 == 0) {
				r2 = 1;
			}
			else if (r0 == 1 && r1 == 1 && r2 == 1 && r3 == 0) {
				r3 = 1;
			}
			else if (r0 == 1 && r1 == 1 && r2 == 1 && r3 == 1 && r4 == 0) {
				r4 = 1;
			}
			else if (r0 == 1 && r1 == 1 && r2 == 1 && r3 == 1 && r4 == 1 && r5 == 0) {
				r5 = 1;
			}
			else if (r0 == 1 && r1 == 1 && r2 == 1 && r3 == 1 && r4 == 1 && r5 == 1 && r6 == 0) {
				r6 = 1;
			}
			else if (r0 == 1 && r1 == 1 && r2 == 1 && r3 == 1 && r4 == 1 && r5 == 1 && r6 == 1 && r7 == 0) {
				r7 = 1;
			}
			else if (r0 == 1 && r1 == 1 && r2 == 1 && r3 == 1 && r4 == 1 && r5 == 1 && r6 == 1 && r7 == 1 && r8 == 0) {
				r8 = 1;
			}
			else if (r0 == 1 && r1 == 1 && r2 == 1 && r3 == 1 && r4 == 1 && r5 == 1 && r6 == 1 && r7 == 1 && r8 == 1 && r9 == 0) {
				r9 = 1;
			}
		}
		else if (c == 'R') {
			if (r9 == 0) {
				r9 = 1;
			}
			else if (r9 == 1 && r8 == 0) {
				r8 = 1;
			}
			else if (r9 == 1 && r8 == 1 && r7 == 0) {
				r7 = 1;
			}
			else if (r9 == 1 && r8 == 1 && r7 == 1 && r6 == 0) {
				r6 = 1;
			}
			else if (r9 == 1 && r8 == 1 && r7 == 1 && r6 == 1 && r5 == 0) {
				r5 = 1;
			}
			else if (r9 == 1 && r8 == 1 && r7 == 1 && r6 == 1 && r5 == 1 && r4 == 0) {
				r4 = 1;
			}
			else if (r9 == 1 && r8 == 1 && r7 == 1 && r6 == 1 && r5 == 1 && r4 == 1 && r3 == 0) {
				r3 = 1;
			}
			else if (r9 == 1 && r8 == 1 && r7 == 1 && r6 == 1 && r5 == 1 && r4 == 1 && r3 == 1 && r2 == 0) {
				r2 = 1;
			}
			else if (r9 == 1 && r8 == 1 && r7 == 1 && r6 == 1 && r5 == 1 && r4 == 1 && r3 == 1 && r2 == 1 && r1 == 0) {
				r1 = 1;
			}
			else if (r9 == 1 && r8 == 1 && r7 == 1 && r6 == 1 && r5 == 1 && r4 == 1 && r3 == 1 && r2 == 1 && r1 == 1 && r0 == 0) {
				r0 = 1;
			}
		}
		else if (c == '0') {
			r0 = 0;
		}
		else if (c == '1') {
			r1 = 0;
		}
		else if (c == '2') {
			r2 = 0;
		}
		else if (c == '3') {
			r3 = 0;
		}
		else if (c == '4') {
			r4 = 0;
		}
		else if (c == '5') {
			r5 = 0;
		}
		else if (c == '6') {
			r6 = 0;
		}
		else if (c == '7') {
			r7 = 0;
		}
		else if (c == '8') {
			r8 = 0;
		}
		else if (c == '9') {
			r9 = 0;
		}
	}

	cout << r0 << r1 << r2 << r3 << r4 << r5 << r6 << r7 << r8 << r9;

	

	return 0;
}

int main() {
	int event = 0;

	cin >> event;

	process(event);

	return 0;
}