// Problem: Write C/C++ program to increase numbers in sentence as follow:
// - Enter a sentence.
// - Find all numbers in the sentence and increase each one to 1.
// - Print the result sentence.
// Input format:
// - Enter a sentence: There are 9 cats and 19 dogs.
// Output format: There are 10 cats and 20 dogs.

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;



int main() {
    char* str = new char[1000001]();
    char *strp = str;
    cin.getline(str, 1000001);

    char* storenum = new char[1000001]();
    char* storenump = storenum;
    
    char* final = new char[1000001]();
    char* finalp = final;

    char* strp2 = nullptr;

    // There are 9 cats and 20 dogs
    // There are 10 cats and 19 dogs

    

    delete[] str;
    delete[] storenum;
    delete[] final;

    strp = nullptr;
    storenump = nullptr;
    finalp = nullptr;

    return 0;
}