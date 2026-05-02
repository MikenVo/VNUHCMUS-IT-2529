#include <iostream>

using namespace std;

void fibonacci(int l[], int n) {
	l[0] = 0; l[1] = 1;

	for (int i = 2; i < n; i++) {
		l[i] = l[i - 1] + l[i - 2];
	}
}

int main() {
	int n; cin >> n;
	int l[n];

	fibonacci(l, n);

	for (int i = 0; i < n; i++) {
		cout << l[i] << " ";
	}

	return 0;
}