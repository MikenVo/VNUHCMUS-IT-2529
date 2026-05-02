// Problem: Write C/C++ program to use pointer as dynamic array:
// - Enter an array of N fractions.
// - Delete fractions having duplicate values (keep the first one).
// - Print the result array.
// Input format:
// - Number of fractions = 5
// - Fraction 0 = 1/2
// - Fraction 1 = 2/5
// - Fraction 2 = 4/8
// - Fraction 3 = 9/7
// - Fraction 4 = 18/14
// Output format: 1/2 2/5 9/7

#include <iostream>
using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};

// Find the greatest common divisor using Euclidean algorithm
int gcd(int firstnum, int secondnum) {
    int result;

    if (firstnum > secondnum) {
        result = secondnum;
        int remainder = firstnum % secondnum;
        while (remainder != 0) {
            firstnum = result;
            result = remainder;
            remainder = firstnum % result;
        }
    }
    else if (firstnum < secondnum) {
        result = firstnum;
        int remainder = secondnum % firstnum;
        while (remainder != 0) {
            secondnum = result;
            result = remainder;
            remainder = secondnum % result;
        }
    }
    else {
        result = firstnum;
    }
    return result;
}



int main() {
    int num; cin >> num; // Specify the number of fractions
    Fraction* arr = new Fraction[num](); // Initialize the Fraction array

    int numerator = 0, denominator = 0;

    for (int i = 0; i < num; i++) {
        cin >> numerator; // Input numerator
        cin >> denominator; // Input denominator

        // Reduce and assign the fraction to the array
        arr[i].numerator = numerator/gcd(numerator,denominator);
        arr[i].denominator = denominator/gcd(numerator,denominator);
    }

    // We save the numerator and denominator of the current fraction
    // Iterate through the array. If we found an equivalent fraction, we erase the duplicate

    int curnum, curdenom;
    for (int i = 0; i < num; i++) {
        curnum = arr[i].numerator; // Take the current numerator
        curdenom = arr[i].denominator; // Take the current denominator

        for (int j = i + 1; j < num; j++) {
            if (curnum == arr[j].numerator && curdenom == arr[j].denominator) { // Check if the current checking fraction is a duplicate
                for (int k = j; k < num - 1; k++) { // Erase the duplicate when it is found
                    arr[k].numerator = arr[k+1].numerator;
                    arr[k].denominator = arr[k+1].denominator;
                }
                num--;
                break;
            }
        }
    }

    // Print out the array
    for (int i = 0; i < num; i++) {
        cout << arr[i].numerator << "/" << arr[i].denominator << " ";
    }

    return 0;
}