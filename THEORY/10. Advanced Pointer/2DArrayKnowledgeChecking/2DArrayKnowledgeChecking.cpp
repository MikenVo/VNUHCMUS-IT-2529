// Problem: Given static 2-D array as follow:
// int m[4][6];
// What types of addresses of the following variables?
// a) m[1][3]
// b) m[0]
// c) m
// Write code to access m[2][4] without using operator [].

#include <iostream>
using namespace std;

int main() {
    int m[4][6] = {0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> m[i][j];
        }
    }

    

    return 0;
}