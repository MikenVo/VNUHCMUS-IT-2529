#include <iostream>

using namespace std;

void swap(float a, float b) {
	float t;
	t = a;
	a = b;
	b = t;

	cout << a << " " << b << endl;
}

int main() {
	float a, b; cin >> a >> b;

	swap(a, b);

	return 0;
}