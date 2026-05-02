#include <iostream>

using namespace std;

int main() {
	double side1, side2, side3;

	while (true) {
		cout << "Type the length of the three sides: "; cin >> side1 >> side2 >> side3;

		if (side1 > 0 && side2 > 0 && side3 > 0) {
			if ((side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1)) {
				if ((side1 == side2) || (side1 == side3) || (side2 == side3)) {
					cout << "Isosceles Triangle" << endl;
					break;
				}
				else if ((side1 == side2) && (side1 == side3) && (side2 == side3)) {
					cout << "Equilateral Triangle" << endl;
					break;
				}
				else if ((side1 * side1 + side2 * side2 == side3 * side3) || (side2 * side2 + side3 * side3 == side1 * side1) || (side1 * side1 + side3 * side3 == side2 * side2)) {
					if ((side1 == side2) || (side1 == side3) || (side2 == side3)) {
						cout << "Right Isosceles Triangle" << endl;
						break;
					}
					else {
						cout << "Right Triangle" << endl;
						break;
					}
				}
				else {
					cout << "Regular Triangle" << endl;
					break;
				}
			}
			else {
				cout << "Not a Triangle" << endl;
				break;
			}
		}
		else {
			cout << "Not a Triangle" << endl;
			continue;
		}
	}
	

	return 0;
}