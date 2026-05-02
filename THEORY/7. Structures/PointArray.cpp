#include <iostream>
#include <cmath>
using namespace std;

struct Point {
	double x;
	double y;

	void Input() {
		cin >> x;
		cin >> y;
	}
};

int main() {
	int n; cin >> n;
	Point* arr = new Point[n];

	for (int i = 0; i < n; i++) {
		arr[i].Input();
	}

	int count = 0;
	int smallest = 0, largest = 0;
	for (int p = 0; p < n; p++) {
		if (arr[p].x > 0) count++;
		if (arr[smallest].x > arr[p].x) smallest = p;
		if (arr[largest].x < arr[p].x) largest = p;
	}

	bool start = false;
	float comparelen = 0, length = 0; int result = 0;

	for (int p = 0; p < n; p++) {
		if (!start) {
			comparelen = sqrt(pow((arr[p].x - 0), 2) + pow((arr[p].y - 0), 2));
			start = true;
			continue;
		}

		length = sqrt(pow((arr[p].x - 0), 2) + pow((arr[p].y - 0), 2));
		if (length < comparelen) {
			comparelen = length;
			result = p;
		}
	}

	cout << "Number of points that have the X-axis value is positive: " << count << endl;
	cout << endl;

	cout << "The point where the X-axis value is smallest: " << "(" << arr[smallest].x << "," << arr[smallest].y << ")" << endl;
	cout << "The point where the X-axis value is biggest: " << "(" << arr[largest].x << "," << arr[largest].y << ")" << endl;
	cout << endl;

	cout << "The point whose distance to the origin (0,0) is the smallest: " << "(" << arr[result].x << "," << arr[result].y << ")" << endl;
	return 0;
}