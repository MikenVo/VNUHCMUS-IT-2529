#include <iostream>

using namespace std;

int main() {
    char answer;

    cout << "Type '1' if you want to convert speed to pace. Type other numbers if you want to convert pace to speed: ";
    cin >> answer;

    if (int(answer) == 49) {
        float speed;

        while (true) {
            cout << "Type speed: "; cin >> speed;

            if (speed > 0) {
                cout << "Result: " << 60/speed << " m/km" << endl;
                break;
            } 
            else {
                cout << "ERROR" << endl;
                continue;
            }
        }
    }
    else {
        float pace;

        while (true) {
            cout << "Type pace: "; cin >> pace;

            if (pace > 0) {
                cout << "Result: " << 60/pace << " km/h" << endl;
                break;
            }
            else {
                cout << "ERROR" << endl;
                continue;
            }
        }
    }

    return 0;
}