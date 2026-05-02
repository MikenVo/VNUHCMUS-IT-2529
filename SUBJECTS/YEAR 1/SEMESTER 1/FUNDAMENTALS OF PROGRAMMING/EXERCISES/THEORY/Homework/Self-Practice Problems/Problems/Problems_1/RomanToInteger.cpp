#include <iostream>
#include <string>

using namespace std;

int romantoInt(string s) {
    int total = 0;

    char one = 'I';
    char five = 'V';
    char ten = 'X';
    char fifty = 'L';
    char hundred = 'C';
    char five_hundred = 'D';
    char one_thousand = 'M';

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == one)
        {
            total += 1;
        }
        else if (s[i] == five)
        {
            total += 5;
        }
        else if (s[i] == ten)
        {
            total += 10;
        }
        else if (s[i] == fifty)
        {
            total += 50;
        }
        else if (s[i] == hundred)
        {
            total += 100;
        }
        else if (s[i] == five_hundred)
        {
            total += 500;
        }
        else if (s[i] == one_thousand)
        {
            total += 1000;
        }
    }

    return total;
}

int main() {
	string s;
	
	cout << "Type your string: "; cin >> s;
	cout << "The number: " << romantoInt(s) << endl;
}