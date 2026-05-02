#include <iostream>

using namespace std;

int main() {
    float a, b, c, min, max;

    cout << "Input a, b and c: "; cin >> a >> b >> c;

    min = a;
    max = a;
    
    if (min > b) {
        min = b;
        if (min > c) {
            min = c;
        }
    }
    else if (min > c) {
        min = c;
    }

    if (max < b) {
        max = b;
        if (max < c) {
            max = c;
        }
    }
    else if (max < c) {
        max = c;
    }

    cout << "Minimun: " << min << endl;
    cout << "Maximun: " << max << endl;
    
    return 0;
}