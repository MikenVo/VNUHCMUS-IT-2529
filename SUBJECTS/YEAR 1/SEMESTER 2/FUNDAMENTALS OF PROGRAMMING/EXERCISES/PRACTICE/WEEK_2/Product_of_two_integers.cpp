#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long a, b;

    while (true) {
        cin >> a >> b;

        if (pow(-10, 9) <= a, b <= pow(10, 9)) {
            long long product = a * b;
            cout << a << " * " << b << " = " << product << endl;
            break;
        }
        else {
            continue;
        }
    }

	return 0;
}