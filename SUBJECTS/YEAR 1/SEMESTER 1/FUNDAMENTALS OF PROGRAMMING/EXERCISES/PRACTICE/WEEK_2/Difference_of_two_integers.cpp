#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int a, b;

	while (true) {
		cin >> a >> b;
	
		if (pow(-10, 9) <= a <= pow(10, 9) && pow(-10, 9) <= b <= pow(10, 9)) {
			cout << a << " - " << b << " = " << a - b << endl;
			break;
		}
		else {
			continue;
		}
	}

	return 0;
}