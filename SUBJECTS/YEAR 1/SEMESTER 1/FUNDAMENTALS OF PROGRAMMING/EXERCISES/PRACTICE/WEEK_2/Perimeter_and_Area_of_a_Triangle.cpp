#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	double edge1, edge2, edge3;
	double area;

	cin >> edge1 >> edge2 >> edge3;

	area = sqrt(((edge1 + edge2 + edge3) / 2) * (((edge1 + edge2 + edge3) / 2) - edge1) * (((edge1 + edge2 + edge3) / 2) - edge2) * (((edge1 + edge2 + edge3) / 2) - edge3));

	cout << fixed << setprecision(2);
	cout << edge1 + edge2 + edge3 << " " << area << endl;

	return 0;
}