#include <iostream>
using namespace std;

// Em test thu Merge Sort
void merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}

void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main() {
	int num; cin >> num;
	int* arr = new int[num];

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	mergeSort(arr, 0, num - 1);

	long long totaltime = 0;
	int i = 0;
	long long result = 0;

	while (i < num) {
		if (totaltime <= arr[i]) {
			result++;
			totaltime += arr[i];
			i++;
		}
		else {
			i++;
		}
	}

	cout << result << endl;

	delete[] arr;
	return 0;
}