// Problem:
// Given the following code:
// int main() {
//     int *x /* Pointer x is pointing to a garbage value */, y = 2;
//     float *z = &y; // Wrong! Different data types

//     *x = *z + y;
//     cout << y << endl;
// }
//
// a) Fix error of the code.
// b) After fixing, what is displayed on screen?


// a) Fixed:
#include <iostream>
using namespace std;

int main() {
    int val = 0;
    int *x = &val, y = 2; // x is a pointer, y is a variable
    int *z = &y; // z is the pointer pointing at y

    *x = *z + y; // Assign the sum of (the value of memory cell pointed by z) and y to (the value of the memory cell pointed by x)
    cout << y << endl; // b) Output: 2

    // If we print out 'val', we will get 4
    // x is pointing at val
    // We dereference x (which is the value of val). We assign the sum of (the value of memory cell pointed by z) and y
    // => val = 2 + 2 (= 4)

    return 0;
}