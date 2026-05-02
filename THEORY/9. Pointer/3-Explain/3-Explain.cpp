// Problem: Explain what the following program prints

#include <iostream>
using namespace std;

int main() {
    double m[100]; // Initialize a double array
    double *p1, *p2; // Initialize two pointers pointing to garbage values

    p1 = m; // p1 is pointing to the first element of the array (Garbage value). p1 = 0
    p2 = &m[6]; // p2 is pointing to the 7th element of the array (Garbage value). p2 = 6
    cout << p2 - p1 << endl; // Expected value: 6
    
    return 0;
}