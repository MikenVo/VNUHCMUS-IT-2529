#include <iostream>

using namespace std;

bool isMagicSquare(int** a, int nRows, int nCols) {
	bool isMagic = true;

	// Calculate the first row
	int pre_rows = 0;
	for (int row = 0; row < 1; row++) {
		for (int col = 0; col < nCols; col++) {
			pre_rows += a[row][col];
		}
	}

	// Check if row is equal
	int sum_cur_row = 0;
	for (int row = 1; row < nRows - 1; row++) {
		for (int col = 0; col < nCols; col++) {
			sum_cur_row += a[row][col];
		}

		if (sum_cur_row != pre_rows) {
			isMagic = false;
			return isMagic;
		}
		else {
			sum_cur_row = 0;
		}
	}

	// Calculate the first col
	int pre_cols = 0;
	for (int col = 0; col < 1; col++) {
		for (int row = 0; row < nRows; row++) {
			pre_cols += a[row][col];
		}
	}

	// Check if column is equal
	int sum_cur_col = 0;
	for (int col = 1; col < nCols - 1; col++) {
		for (int row = 0; row < nRows; row++) {
			sum_cur_col += a[row][col];
		}

		if (sum_cur_col != pre_cols) {
			isMagic = false;
			return isMagic;
		}
		else {
			sum_cur_col = 0;
		}
	}

	// Calculate first diagonal
	int sum_left_diagonal = 0;
	int cur_box = 0;

	while (cur_box < nRows) {
		sum_left_diagonal += a[cur_box][cur_box];
		cur_box++;
	}

	// Calculate second diagonal
	int sum_right_diagonal = 0;
	int row_cur_box = 0;
	int col_cur_box = nCols - 1;

	while (row_cur_box < nRows) {
		sum_right_diagonal += a[row_cur_box][col_cur_box];
		row_cur_box++;
		col_cur_box--;
	}

	if (sum_left_diagonal != sum_right_diagonal) {
		isMagic = false;
		return isMagic;
	}

	return isMagic;
}

int main() {
	int nRows, nCols; cin >> nRows >> nCols;

	// Allocate memory
	int** arr = new int* [nRows];
	for (int i = 0; i < nRows; i++) {
		arr[i] = new int[nCols];
	}

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			cin >> arr[i][j];
		}
	}

	// Check if magic square
	if (isMagicSquare(arr, nRows, nCols)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	// Deallocate memory
	for (int i = 0; i < nRows; i++) {
		delete[] arr[i];
	}
	delete[] arr;


	return 0;
}