// Version 1
/*
#include <iostream>

using namespace std;

int main() {
    int plate;

    while (true) {
        int output;

        cout << "Type your plate: "; cin >> plate;

        if (to_string(plate).length() == 5) {
            int total = 0;
            int i = 0;

            while (i <= 5) {
                total += plate % 10;
                plate /= 10;
                i++;
            }

            output = total % 10;

            cout << "Score: " << output << endl;
            break;
        }
        else {
            cout << "ERROR" << endl;
            continue;
        }
    }
    return 0;
}
*/

// Version 2
#include <iostream>

using namespace std;

int main()
{
    int plate;

    while (true)
    {
        int output;

        cout << "Type your plate: ";
        cin >> plate;

        if (to_string(plate).length() == 5)
        {
            int total = 0;
            int i = 0;

            while (i <= 5)
            {
                total += plate % 10;
                plate /= 10;
                i++;
            }

            output = total;

            if (output >= 10) {
                output = (output % 10) + (output/10);
            }

            cout << "Score: " << output << " points" << endl;
            break;
        }
        else
        {
            cout << "ERROR" << endl;
            continue;
        }
    }
    return 0;
}