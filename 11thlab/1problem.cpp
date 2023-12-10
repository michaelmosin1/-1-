#include <iostream>
using namespace std;


void quicksort(int* massive, int start, int end){
	if (start > end) return;
	int pivot = massive[(start+end)/2]%10;
	int i = start;
	int j = end;
	while (i <= j)
	{
	while ((massive[i]%10) > pivot) i++;
	while ((massive[j]%10) < pivot) j--;
	if (i <= j)
	{
	int tmp = massive[j];
	massive[j] = massive[i];
	massive[i] = tmp;
	i++;
	j--;
	}
	}
	quicksort(massive, start, j);
	quicksort(massive, i, end);
}


int main() {
	short j; //Value of variables that we input
	bool same_values = false; //Flag that says that we have 2 same values in massive
	int* massive;
	cout << "Please input j" << endl;
	cin >> j;
	if ((j > 0) && (j < 10000))
	{
	massive = new int[j];
	}
	else 
	{
		cerr << "Error! Invalid j" << endl;
		return 200;

	}
	cout << "Input elements of the massive" << endl;
	for (short i = 0; i < j; i++) {
		cin >> massive[i];
	}
	cout << endl;
	for (short a = 0; a < j - 1; a++)
		for (short b = a + 1; b < j; b++) { //Searches same values
			if (massive[a] == massive[b]) {
				same_values = true;
				break;
			}
		}
	if (same_values) { //Sort cycle for massive
		quicksort(massive, 0, j-1);
		for (short i = 0; i < j; i++) { //Prints massive after sort
			cout << massive[i] << " ";
		}
		cout << endl;
	}
	else
		cout << "Same values weren'n found" << endl;
	return 0;
}
