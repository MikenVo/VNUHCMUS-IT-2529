#include <iostream>
#include <cmath>

using namespace std;

// Structure holds circle properties
struct Circle {
	// The center of the circle
	float x;
	float y;

	// The radius of the circle
	float radius;
};

void printRelation(Circle c1, Circle c2) {
	// Find the distance between two center
	float distance_between_two_centers = sqrt(pow((c2.x - c1.x), 2) + pow((c2.y - c1.y), 2));

	if (distance_between_two_centers == 0) { // If the distance between two center = 0
		cout << "Coincident" << endl;
	}
	else if (distance_between_two_centers == c1.radius + c2.radius) { // If the distance between two center = the sum of two radius
		cout << "Externally Tangent" << endl;
	}
	else if (distance_between_two_centers == abs(c1.radius - c2.radius)) { // If the distance between two center = the difference of two radius
		cout << "Internally Tangent" << endl;
	}
	else if (distance_between_two_centers < (c1.radius - c2.radius)) { // If the distance between two center < the difference of two radius
		cout << "One contains the other" << endl;
	}
	else if (distance_between_two_centers < (c1.radius + c2.radius)) { // If the distance between two center < the sum of two radius
		cout << "Intersect" << endl;
	}
	else if (distance_between_two_centers > (c1.radius + c2.radius)) { // If the distance between two center > the sum of two radius
		cout << "Separate" << endl;
	}

}

int main() {
	Circle c1, c2;
	cin >> c1.x >> c1.y >> c1.radius;
	cin >> c2.x >> c2.y >> c2.radius;

	printRelation(c1, c2);

	return 0;
}