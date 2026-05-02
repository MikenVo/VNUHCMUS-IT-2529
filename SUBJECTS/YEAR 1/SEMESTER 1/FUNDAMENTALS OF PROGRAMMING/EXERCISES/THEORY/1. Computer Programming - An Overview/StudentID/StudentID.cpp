#include <iostream>

using namespace std;

int main() {
    int studentid;

    while (true) {
        cout << "Type your studend ID: "; cin >> studentid;

        if (to_string(studentid).length() == 8) {
            int sequence, programtype, faculty, admissionyear;

            sequence = studentid % 10000;
            studentid /= 1000;

            programtype = studentid % 10;
            studentid /= 10;

            faculty = studentid % 100;
            studentid /= 100;

            admissionyear = studentid % 100;
            studentid /= 100;
        
            cout << "- Sequence: " << sequence << endl
                << "- Type of program: " << programtype << endl
                << "- Faculty: " << faculty << endl
                << "- Admission year: " << admissionyear << endl;
            break;
        }
        else {
            cout << "ERROR" << endl;
            continue;
        }
    }

    return 0;
}