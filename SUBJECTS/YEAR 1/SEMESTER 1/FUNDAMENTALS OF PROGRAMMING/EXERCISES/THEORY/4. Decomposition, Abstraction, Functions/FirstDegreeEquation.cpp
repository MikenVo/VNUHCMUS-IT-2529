#include <iostream>

using namespace std;

void LinearEquation(float a, float b, float c) {
	if (a == 0 && b == 0) {
		cout << "Infinite Solutions" << endl;
	}
	else if (a == 0 && b != 0) {
		cout << "No Solution" << endl;
	}
	else if (a != 0 && b == 0) {
		cout << c / a << endl;
	}
	else if (a != 0 && b != 0) {
		cout << -b / a << endl;
	}
}

int main() {
	float a, b, c; cin >> a >> b >> c;
	b -= c; c = 0;
	
	LinearEquation(a, b, c);
	
	return 0;
}