#include <iostream>

using namespace std;

int main() {
    float math_score, phy_score, chem_score;
    float math_coe = 2.0, phy_coe = 2.0, chem_coe = 2.0;

    while (true) {
        cout << "Type your Mathematics, Physics and Chemistry scores: "; cin >> math_score >> phy_score >> chem_score;

        if (math_score >= 0 && phy_score >= 0 && chem_score >= 0) {
            if (math_score <= 10 && phy_score <= 10 && chem_score <= 10) {
                cout << "Result: " << (math_coe*math_score + phy_coe*phy_score + chem_coe*chem_score)/6 << endl;
                break;
            }
            else {
                cout << "ERROR" << endl;
                continue;
            }
        }
        else {
            cout << "ERROR" << endl;
            continue;
        }
    }

    return 0;
}