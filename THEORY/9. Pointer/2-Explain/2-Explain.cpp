// Problem: Explain the difference amongst the following 3 functions

#include <iostream>
using namespace std;

void swap1(int x, int y) { // Pass by value
    // The function will make copies (x and y) that have the same values as the values passed into the function
    // If we modify the variables in the function, the actual values outside the function won't be changed

    // Example: We pass in 3 and 4 (x = 3, y = 4)
    int temp = x; // temp = x = 3
    x = y; // x = y = 4
    y = temp; // y = temp = 3

    // Result: x = 4, y = 3
}

void swap2(int &x, int &y) { // Pass by reference
    // The function won't make copies like pass by value, it works directly with the values/variables passed into.
    // Therefore, if we change the values in the function, the actual values in variables outside will be changed too

    // Example: We have two variable num1 = 3, num2 = 4
    // We pass these variables into the function: void swap2(num1, num2) {...}
    int temp = x; // temp = x = 3
    x = y; // x = y = 4
    y = temp; // y = temp = 3

    // Result: x = 4, y = 3. num1 = 4, num2 = 3
}

void swap3(int *x, int *y) { // Pass by pointer
    // We must pass pointers into the function instead of values or regular variables

    // Example: Outside the function
    // int num1 = 3, num2 = 4;
    // int *p1 = &num1, *p2 = &num2;
    // We pass these pointers into the function: void swap3(p1, p2) {...}
    int temp = *x; // temp = *x (num1) = 3
    *x = *y; // *x (num1) = *y (num2) = 4
    *y = temp; // *y (num2) = temp = 3

    // Result: x, y remain unchanged. num1 = 4, num2 = 3
}

int main() {
    cout << "Outputs" << endl;
    int num1 = 3, num2 = 4;

    // Swap 1
    swap1(num1, num2);
    cout << num1 << " " << num2 << endl; // Expected outputs: num1 = 3, num2 = 4

    // Swap 2
    num1 = 3, num2 = 4;
    swap2(num1, num2);
    cout << num1 << " " << num2 << endl; // Expected outputs: num1 = 4, num2 = 3

    // Swap 3
    num1 = 3, num2 = 4;
    int *p1 = &num1, *p2 = &num2;
    swap3(p1, p2);
    cout << num1 << " " << num2 << endl; // Expected outputs: num1 = 4, num2 = 3

    return 0;
}