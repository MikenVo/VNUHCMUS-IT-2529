#include <iostream>
#include <cstring>

using namespace std;

// "6", "7", "8", "9", "T", "J", "Q", "K" and "A"
// "6", "7", "8", "9", "84", "74", "81", "75" and "65"

/*
* To beat:
* - If a card has trump suit and another one doesn't.
* - Same suit, different rank.
*/

//if (
	//	(one == 'A' /* A */ && (two < 'A' || two == 'K' || two == 'Q' || two == 'J' || two == 'T')) || // A - 65
	//	(one == 'K' /* K */ && (two < 'K' && two != 'A') || two == 'Q' || two == 'J' || two == 'T') || // K - 75
	//	(one == 'Q' && ((two < 'Q' && two != 'A') && two != 'K')) || // Q - 81
	//	(one == 'J' && (two < 'J' && two != 'A')) || // J
	//	(one == 'T' && (two < 'T' && two != 'A' && two != 75 && two != 81 && two != 74)) || // T
	//	(one == 57 && two < 57) ||
	//	(one == 56 && two < 56) ||
	//	(one == 55 && two < 55) ||
	//	(one == 54 && two < 54)
	//	) {
	//	return true;
	//}
	//else {
	//	return false;
	//}

bool IsHigher(char one, char two) {
	char ranks[10] = { '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };

	int indexcard1 = 0, indexcard2 = 0;

	for (int i = 0; i < strlen(ranks); i++) {
		if (ranks[i] == one) {
			indexcard1 = i;
		}

		if (ranks[i] == two) {
			indexcard2 = i;
		}
	}

	if (indexcard1 > indexcard2) {
		return true;
	}

	return false;
}

int main() {
	char trump; cin >> trump;

	char firstcard[3]; cin >> firstcard;

	char secondcard[3]; cin >> secondcard;

	if ((firstcard[1] == trump && secondcard[1] != trump)) {
		cout << "YES" << endl;
	}
	else if ((firstcard[1] == secondcard[1])) {
		if (IsHigher(firstcard[0], secondcard[0])) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}