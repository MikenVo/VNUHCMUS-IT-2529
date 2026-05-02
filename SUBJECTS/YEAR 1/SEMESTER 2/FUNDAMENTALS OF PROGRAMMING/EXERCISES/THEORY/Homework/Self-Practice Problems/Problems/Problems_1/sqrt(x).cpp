#include <iostream>
#include <cmath>

using namespace std;

int mySqrt(int x) {
    /*double guess = 0;

    if (x == 1 || x == 0) {
        return x;
    }
    else if (x % 2 == 0 && x < 1000000 || x % 2 != 0 && x < 1000000) {
        guess = x / 2.0;
    }
    else if ((x % 2 != 0 && x > 1000000 && x <= 9999999) ||
        (x % 2 == 0 && x >= 1000000 && x <= 999999999)) {
        guess = x / 30000.0;
    }
    else {
        guess = x / 100000000.0;
    }

    while (true) {
        if ((guess * guess) - x < 1.0f && (guess * guess) - x >= 0) {
            return floor(guess);
        }
        else {
            guess = (guess + x / guess) / 2;
            continue;
        }
    }*/

    int low = 1, high = x, mid = 0, possible;

    if (x == 0 || x == 1) {
        return x;
    }
    else {
        while (low <= high) {
            mid = (low + high) / 2;
            if (mid * mid == x) {
                return mid;
            }
            else if (mid * mid > x) {
                high = mid - 1;
            }
            else if (mid * mid < x) {
                low = mid + 1;
                possible = mid;
            }
        }

            return possible;
    }
}

int main() {
	int x;

	cout << "Type a number: "; cin >> x;
    cout << "Answer: " << mySqrt(x) << endl;

    return 0;
}