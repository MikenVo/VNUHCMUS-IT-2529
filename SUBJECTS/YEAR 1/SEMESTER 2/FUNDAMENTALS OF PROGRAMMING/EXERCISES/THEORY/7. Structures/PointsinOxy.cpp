#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
	float x;
	float y;
};

int main() {
	Point point1, point2;

	cout << "---- Point 1 ----" << endl;
	cout << "Type the x-coordinate of point 1: "; cin >> point1.x;
	cout << "Type the y-coordinate of point 1: "; cin >> point1.y;
	cout << endl;

	cout << "---- Point 2 ----" << endl;
	cout << "Type the x-coordinate of point 2: "; cin >> point2.x;
	cout << "Type the y-coordinate of point 2: "; cin >> point2.y;
	cout << endl;

	/*---- Calculate the distance of two points ----*/
	float distance = sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));

	cout << "---- Result ----" << endl;
	cout << fixed << setprecision(2);
	cout << "The distance between point (" << point1.x << ", " << point1.y << ") and point (" << point2.x << ", " << point2.y << ") is " << distance << endl;
	cout << endl;

	/*----Find symmetric point from the X-axis ----*/
	cout << "-- The symmetric point from the X-axis --" << endl;
	point1.y = 0 - point1.y;
	cout << "The symmetric point from the X-axis: " << "(" << point1.x << ", " << point1.y << ")" << endl;
	point2.y = 0 - point2.y;
	cout << "The symmetric point form the X-axis: " << "(" << point2.x << ", " << point2.y << ")" << endl;
	cout << endl;

	/*---- Find symmetric point from the origin (0, 0) ----*/
	cout << "-- The symmetric point from the origin (0, 0) --" << endl;
	point1.x = 0 - point1.x;
	cout << "The symmetric point from the origin: " << "(" << point1.x << ", " << point1.y << ")" << endl;
	point2.x = 0 - point2.x;
	cout << "The symmetric point from the origin: " << "(" << point2.x << ", " << point2.y << ")" << endl;
	cout << endl;

	return 0;
}