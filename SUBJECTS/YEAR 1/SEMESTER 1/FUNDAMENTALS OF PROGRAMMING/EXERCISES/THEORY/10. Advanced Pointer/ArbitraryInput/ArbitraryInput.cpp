// Problem: Write C/C++ program to input a paragraph with arbitrary length:
// - Enter a long paragraph until input '.' and new line
// - Print the paragraph
// Note: Use dynamic string

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    // Initialization
    int MAX_LENGTH = 1000001; // Set the max length for a memory-allocated array
    char ch; // Store a character inputted by the user
    int lencount = 0; // Track the number of inputted characters

    char* str = new char[MAX_LENGTH](); // Create memory-allocated array with the length of MAX_LENGTH
    char* strp = str; // Initialize a pointer pointing at the first element of the str array
    char* str2 = nullptr; // Intitialize another pointer to create a new memory-allocated array when 1st is full

    // ---

    // Running a loop until '.' is found in the string
    while (cin.get(ch) && ch != '.') {
        lencount++; // Increase the counter to check if the array has been full yet
        if (lencount == MAX_LENGTH) { // Check if the array has been full yet
            MAX_LENGTH += MAX_LENGTH; // Increase the MAX_LENGTH
            str2 = new char[MAX_LENGTH](); // Assign the pointer to a new memory-allocated array
            strcpy(str2, str); // Copy the content of old string to the new string
            delete[] str; // Deallocate the old string
            str = str2; // Point the old string pointer to the new string
            strp = str;
            strp += lencount - 1; // Set the pointer to the end of the new string
            str2 = nullptr; // Set back to nullptr to use in the next "moving"

            *(strp++) = ch; // Assign the current character to the string after "moving"
        }
        else {
            *(strp++) = ch; // Assign the current character to the string
        }
    }

    // When the current character is '.', the loop will be stopped
    // Therefore, we need to increase the character count and assign the '.' to the last position
    lencount++;
    str[lencount - 1] = '.';

    cout << str << endl; // Print out the string

    // ---

    delete[] str; // Deallocate the array

    // Set the pointer to nullptr
    str = nullptr;
    str2 = nullptr;

    return 0;
}