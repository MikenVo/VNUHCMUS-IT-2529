// Problem: Explain what the following program prints

#include <iostream>
using namespace std;

int main() {
    int x = 1023; // Initialize an integer variable

    // 1023 is stored as binary in the computer
    // 1023(10) = 00000000 00000000 00000011 11111111(2)
    // (char*) tells the computer to treat each byte as an individual characters
    char *p = (char *)&x; 
    // p doesn't point to an "element" in the traditional sense, it points to the first byte of the integer x
    // In most computer the byte contains the least significant byte is considered the first byte.
    
    // p[0] = 11111111
    // p[1] = 00000011
    // p[2] = 00000000
    // p[3] = 00000000

    // Because each byte is treated as individual characters we need to tell the computer to treat those individual characters as integer
    // The reason why p[0] has (unsigned char) because char is signed by default (-128 to 127)
    // The computer sees p[0] = 11111111 as negative number (= -1(10)). Therefore, it will display -1 instead of 255
    
    // However, the computer sees p[1] = 00000011 as positive number (= 3(10)). Therefore, it will display 3
    cout << (int)(unsigned char)p[0] << " " << (int)p[1] << " " << (int)p[2] << " " << (int)p[3] << endl; // Expected outputs: 255 3 0 0

    return 0;
}