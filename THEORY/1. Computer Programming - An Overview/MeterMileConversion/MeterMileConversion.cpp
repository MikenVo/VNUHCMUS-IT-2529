#include <iostream>

using namespace std;

int main() {
    int answer;

    cout << "Type '1' if you want to convert meter to mile. Type others to convert mile to meter: ";
    cin >> answer;

    if (answer == 1) {
        float meter;

        while (true) {
            cout << "Type meter(s): "; cin >> meter;
            if (meter >= 0) {
                cout << "Result: " << meter/1609.344 << endl;
                break;
            }
            else {
                cout << "ERROR" << endl;
                continue;
            }
        }
    }
    else {
        float miles;

        while (true) {
            cout << "Type mile(s): "; cin >> miles;
            if (miles >= 0) {
                cout << "Result: " << miles*1609.344 << endl;
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