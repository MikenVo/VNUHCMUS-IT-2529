#include <iostream>

using namespace std;

void Add(int l[], int& n, int e) {
	n++;
	l[n - 1] = e;
}

void Remove(int l[], int& n, int e) {
	int Index = 0;

	for (int i = 0; i < n; i++) {
		if (e == l[i]) {
			Index = i;
			break;
		}
	}

	for (int i = Index; i < n; i++) {
		l[i] = l[i + 1];
	}
	n--;
}

int main() {
	int n; cout << "Type the number of elements: "; cin >> n;
	int l[n];

	cout << "Type the numbers: ";
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	int ans;
	cout << "Press 0 to add an element, 1 to remove an element: "; cin >> ans;

	if (ans == 0) {
		int e;
		cout << "Type the element you want to add: "; cin >> e;
		Add(l, n, e);

		cout << "New list: ";
		for (int i = 0; i < n; i++) {
			cout << l[i] << " ";
		}
	}
	else if (ans == 1) {
		int e;
		cout << "Type the element you want to remove: "; cin >> e;
		Remove(l, n, e);

		cout << "New list: ";
		for (int i = 0; i < n; i++) {
			cout << l[i] << " ";
		}
	}

	return 0;
}