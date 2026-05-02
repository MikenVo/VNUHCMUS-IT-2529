#include <iostream>
#include <fstream>
using namespace std;

// Bubble sort
void sorted(int arr[], int n) {
	bool swapped = false;
	for (int i = 0; i < n; i++) {
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}
	}
}

int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");

	if (input && output) {
		int n; input >> n;
		int* arr = new int[n];
		int m;

		// Get the numbers from the input text file and assign them into an array
		for (int i = 0; i < n; i++) {
			input >> m;
			arr[i] = m;
		}

		// Sort the arrary using bubble sort
		sorted(arr, n);

		// Print the sorted array to the output text file
		output << "[";
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				output << arr[i];
			}
			else output << arr[i] << ", ";
		}
		output << "]" << endl;
	}
	else {
		cout << "ERROR" << endl;
		return 1;
	}

	input.close();
	output.close();
	return 0;
}