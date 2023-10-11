#include <iostream>


bool same_digits(int n)
{
	bool flag = false;
		while (n != 0) {
			short digit = n % 10;
			n /= 10;
			//int n_check = n;
			while (n != 0) {
				if (digit == n % 10) {
					flag = true;
					break;
				}
				n /= 10;
			}
			if (n == 0)
				flag = true;
			if (flag == true)
				break;
		}
	return flag;
}


bool mltpl_14(int n) {
	bool is_2 = false;
	bool is_7 = false;
		while (n != 0) {
			if ((n % 10) == 2) {
				is_2 = true;
			}
			if ((n % 10) == 7) {
				is_7 = true;
			}
			if (is_2 && is_7)
				break;
			n /= 10;
		}
	return (is_2 && is_7);
}


int main() {
	short array_length;
	unsigned int array[10000] = {};
	std::cout << "Please input massive length:" << std::endl;
	std::cin >> array_length;
	std::cout << "Please input massive elements:" << std::endl;
	//a - first variable-counter
	//b - second variable-counter
	for (short i = 0; i < array_length; i++) {
		std::cin >> array[i];
	}
	for (short a = 0; a < array_length; a++) {
		if (!same_digits(array[a])) {
			for (short b = a; b < array_length; b++) {
				array[b] = array[b + 1];
			}
			array_length--;
			a--;
		}
	}
	for (short a = 0; a < array_length; a++) {
		if (mltpl_14(array[a])) {
			for (short b = array_length; b > a; b--) {
				array[b] = array[b - 1];
			}
			array_length++;
			a++;
		}
	}
	for (short i = 0; i < array_length; i++) {
		std::cout << array[i] << " ";
	}
	return 0;
}