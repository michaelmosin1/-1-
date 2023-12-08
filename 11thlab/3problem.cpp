#include <iostream>
#include <limits.h>
using namespace std;


int main() {
	short i;
	short j;
	cout << "Please input width and height of matrix" << endl;
	cin >> i >> j;
	int column_summ;
	int min_summ = INT_MAX;
	int min_column_number;
	int** matrix;
	if ((i > 0) && (i < 101) && (j > 0) && (j < 101))
	{
		matrix = new int*[i];
		for (short a = 0; a < i; a++) matrix[a] = new int[j];
	}
	else 
	{
		cerr << "Error! Wrong size of matrix" << endl;
		return 200;
	}
	cout << "Please input elements of matrix line-by-line:" << endl;
	for (short a = 0; a < j; a++)
		for (short b = 0; b < i; b++) {
			cin >> matrix[a][b];
		}
	cout << endl;
	for (short b = 0; b < j; b++) { //a - strings, b - columns
		column_summ = 0;
		for (short a = 0; a < i; a++) {
			column_summ += matrix[a][b];
		}
		if (column_summ < min_summ) {
			min_summ = column_summ;
			min_column_number = b;
		}
	}
	for (short a = 0; a < i; a++) {
		matrix[a][min_column_number] += 3;
	}
	for (short a = 0; a < j; a++) {
		for (short b = 0; b < i; b++) {
			cout << matrix[a][b] << " ";
		}
		cout << endl;
	}
	return 0;
}