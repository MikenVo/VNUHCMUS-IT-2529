#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double meter;
	double mile;

	while (true) {
		cout << "Type your meter and mile: "; cin >> meter >> mile;

		if (meter < 0 && mile < 0) {
			cout << "ERROR" << endl;
			continue;
		}
		else {
			cout << "meter -> mile: " << meter / 1609.344 << endl;
			cout << "mile -> meter: " << mile * 1609.344 << endl;
			break;
 		}
	}

	return 0;
}