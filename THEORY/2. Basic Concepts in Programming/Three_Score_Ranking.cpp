#include <iostream>

using namespace std;

int main() {
	float score1, score2, score3;
	
	while (true) {
		cout << "Type the score of three students: "; cin >> score1 >> score2 >> score3;

		if (score1 < 0 && score2 < 0 && score3 < 0) {
			cout << "ERROR" << endl;
			continue;
		}
		else {
			if (score1 > score2 && score1 > score3) {
				score1 = 1;
				if (score2 > score3) {
					score2 = 2;
					score3 = 3;
				}
				else if (score3 < score2) {
					score2 = 3;
					score3 = 2;
				}
				else {
					score2 = score3 = 2;
				}
			}
			else if (score2 > score1 && score2 > score3) {
				score2 = 1;
				if (score1 > score3) {
					score1 = 2;
					score3 = 3;
				}
				else if (score3 > score1) {
					score1 = 3;
					score3 = 2;
				}
				else {
					score3 = score1 = 2;
				}
			}
			else if (score3 > score1 && score3 > score2) {
				score3 = 1;
				if (score2 > score1) {
					score2 = 2;
					score1 = 3;
				}
				else if (score1 > score2) {
					score1 = 3;
					score2 = 2;
				}
				else {
					score1 = score2 = 2;
				}

			}
			else if (score1 < score2 && score1 < score3) {
				score1 = 3;
				if (score2 > score3) {
					score2 = 1;
					score3 = 2;
				}
				else if (score3 > score2) {
					score3 = 1;
					score2 = 2;
				}
				else {
					score3 = score2 = 1;
					score1 = 2;
				}
			}
			else if (score2 < score1 && score2 < score3) {
				score2 = 3;
				if (score1 > score3) {
					score1 = 1;
					score3 = 2;
				}
				else if (score3 > score1) {
					score1 = 2;
					score3 = 1;
				}
				else {
					score3 = score1 = 1;
					score2 = 2;
				}
			}
			else if (score3 < score1 && score3 < score2) {
				score3 = 3;
				if (score1 < score2) {
					score1 = 2;
					score2 = 1;
				}
				else if (score1 > score2) {
					score1 = 1;
					score2 = 2;
				}
				else {
					score1 = score2 = 1;
					score3 = 2;
				}
			}

			cout << "Ranking: " << score1 << " " << score2 << " " << score3 << endl;
			break;
		}
	}
	return 0;
}