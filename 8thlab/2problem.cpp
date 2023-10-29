#include <iostream>
#include <fstream>


short length(char massive[]) {
	short leng = 0;
	while (massive[leng] != '\0') {
		leng++;
	}
	return leng;
}


void word_processing(char massive[]) {
	short a = 0;
	while (massive[a] != '\0') {
		if (ispunct(massive[a]) && (massive[a] != '-')) {
			massive[a] = '\0';
		}
		if (isdigit(massive[a])) {
			massive[a] = '\0';
		}
		massive[a] = tolower(massive[a]);
		a++;
	}
}


short number_of_vowels(char massive[]) {
	char alphabet[21] = { "àå¸èîóûýþÿ" };
	short a = 0;
	short count = 0;
	while (massive[a] != '\0') {
		for (short b = 0; b < sizeof(alphabet); b++) {
			if (massive[a] == alphabet[b]) {
				count++;
				break;
			}
		}
		a++;
	}
	return count;
}


bool is_palindrom(char massive[]) {
	short len = length(massive) - 1;
	if (len > 0) {
		for (short i = 0; i <= len / 2; i++) {
			if (massive[i] != massive[len - i]) {
				return false;
			}
		}
		return true;
	}
	else return false;
}


void double_vowels(char massive[]) {
	char alphabet[21] = "àå¸èîóûýþÿ";
	short i = 0;
	while (massive[i] != '\0') {
		for (short b = 0; b < length(alphabet); b++) {
			if (massive[i] == alphabet[b]) {
				for (short c = length(massive); c >= i + 1; c--) {
					massive[c] = massive[c - 1];
				}
				massive[i + 1] = massive[i];
				i++;
				break;
			}
		}
		i++;
	}
}


int main(){
	const int N = 2000;
	short number_of_words;
	char string[N][101] = {};
	bool has_palindrom = false;
	short i = 0;
	std::cout << "Please input number of words" << std::endl;
	std::cin >> number_of_words;
	setlocale(LC_ALL, "Russian");
	std::ifstream in("input.txt");
	while (!in.eof() && i < N) {
		char word[101] = {};
		in >> word;
		word_processing(word);
		for (short a = 0; a <= length(word); a++) {
			string[i][a] = word[a];
		}
		if (is_palindrom(string[i])) {
			has_palindrom = true;
		}
		i++;
	}
	in.close();
	if (has_palindrom) {
		for (short a = 0; a < number_of_words - 1; a++) {
			for (short b = a + 1; b < number_of_words; b++) {
				if (number_of_vowels(string[b]) > number_of_vowels(string[a])) {
					std::swap(string[b], string[a]);
				}
			}
		}
	}
	else {
		for (short a = 0; a < number_of_words - 1; a++) {
			for (short b = a + 1; b < number_of_words; b++) {
				for (short c = 0; c < length(string[a]); c++) {
					if (string[a][c] > string[b][c]) {
						std::swap(string[a], string[b]);
					}
					else if (string[a][c] == string[a][c])
						c++;
				}
			}
		}
		for (short i = 0; i < number_of_words; i++) {
			double_vowels(string[i]);
		}
	}
	
	for (short i = 0; i < number_of_words; i++) {
		std::cout << string[i] << std::endl;
	}
	return 0;
}