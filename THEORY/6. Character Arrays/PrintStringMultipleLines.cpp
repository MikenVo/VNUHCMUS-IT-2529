#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char str[1000]; int n;

	cout << "Type your string: "; cin.getline(str, 1000);
	cout << "How many times do you want to print? "; cin >> n;

	for (int i = 0; i < n; i++) {
		cout << str << endl;
	}

	return 0;
}