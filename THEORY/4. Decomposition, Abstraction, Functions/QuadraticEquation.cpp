#include <iostream>
#include <cmath>

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

void QuadraticEquation(float a, float b, float c) {
	float delta = b * b - 4 * a * c;

	if (delta < 0) {
		cout << "No Solution" << endl;
	}
	else if (delta == 0) {
		cout << -b / 2 * a << endl;;
	}
	else {
		cout << (-b + sqrt(delta)) / 2 * a << endl;
		cout << (-b + sqrt(delta)) / 2 * a << endl;
	}
}

int main() {
	float a, b, c, d; cin >> a >> b >> c >> d;
	c -= d; d = 0;

	if (a == 0) {
		LinearEquation(b, c, d);
	}
	else {
		QuadraticEquation(a, b, c);
	}
}