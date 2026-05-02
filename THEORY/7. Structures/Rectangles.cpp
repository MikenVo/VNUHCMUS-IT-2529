#include <iostream>
#include <cmath>

using namespace std;

struct Point2D {
	double x;
	double y;
};

struct rectangle {
	Point2D topleft;
	Point2D bottomleft;
	Point2D topright;
	Point2D bottomright;
};

int main() {
	rectangle rec;

	cout << "---- Input ----" << endl;
	cout << "Type the coordinate for top left point: "; cin >> rec.topleft.x >> rec.topleft.y;
	cout << "Type the coordinate for bottom left point: "; cin >> rec.bottomleft.x >> rec.bottomleft.y;
	cout << "Type the coordinate for bottom right point: "; cin >> rec.bottomright.x >> rec.bottomright.y;
	cout << "Type the coordinate for top right point: "; cin >> rec.topright.x >> rec.topright.y;
	cout << endl;

	/*---- Check validation ----*/
	// Vector topright->topleft
	Point2D topltopr;
	topltopr.x = rec.topleft.x - rec.topright.x;
	topltopr.y = rec.topleft.y - rec.topright.y;
	// Vector topleft->bottomleft
	Point2D toplbotl;
	toplbotl.x = rec.bottomleft.x - rec.topleft.x;
	toplbotl.y = rec.bottomleft.y - rec.topleft.y;
	// Vector bottomleft->bottomright
	Point2D botlbotr;
	botlbotr.x = rec.bottomright.x - rec.bottomleft.x;
	botlbotr.y = rec.bottomright.y - rec.bottomleft.y;
	// Vector bottomright->topright
	Point2D botrtopr;
	botrtopr.x = rec.topright.x - rec.bottomright.x;
	botrtopr.y = rec.topright.y - rec.bottomright.y;

	if (topltopr.x * toplbotl.x + topltopr.y * toplbotl.y != 0 ||
		toplbotl.x * botlbotr.x + toplbotl.y * botlbotr.y != 0 ||
		botlbotr.x * botrtopr.x + botlbotr.y * botrtopr.y != 0 ||
		botrtopr.x * topltopr.x + botrtopr.y * topltopr.y != 0) {
		return 1;
	}

	double distance1 /*topright->topleft*/ = sqrt(pow(topltopr.x, 2) + pow(topltopr.y, 2));
	double distance2 /*topleft->bottomleft*/ = sqrt(pow(toplbotl.x, 2) + pow(toplbotl.y, 2));

	cout << "---- Result ----" << endl;
	/*---- Perimeter ----*/
	cout << "Perimeter: " << 2 * (distance1 + distance2) << endl;
	/*---- Area ----*/
	cout << "Area: " << distance1 * distance2 << endl;


}