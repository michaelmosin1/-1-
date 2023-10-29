#include <fstream>
#include <iostream>


short length(char word[]) {
	short leng = 0;
	while (word[leng] != '\0') {
		leng++;
	}
	return leng;
}


char touppper(char letter) {
	if ((letter >= -32) && (letter <= -1)) {
		letter -= 32;
	}
	return letter;
}


int main() {
	setlocale(LC_ALL, "Russian");
	char alphabet[67] = "àáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿ";
	short count[33] = {};
	std::ifstream in("input.txt");
	while (!in.eof()) {
		char word[101] = {};
		in >> word;
		for (short i = 0; i < length(word); i++) {
			for (short j = 0; j < length(alphabet); j++) {
				if (word[i] == alphabet[j])
					count[j]++;
			}
		}
	}
	in.seekg(0);
	for (short a = 0; a < length(alphabet) - 1; a++) {
		for (short b = a + 1; b < length(alphabet); b++) {
			if (count[b] > count[a]) {
				std::swap(alphabet[a], alphabet[b]);
				std::swap(count[a], count[b]);
			}
		}
	}
	std::ofstream out("output.txt");
	while (!in.eof()) {
		char word[101] = {};
		in >> word;
		short len = length(word);
		for (short i = 0; i < len - 1; i++) {
			for (short a = 0; a < 4; a++) {
				for (short b = 0; b < 4; b++) {
					if ((word[i] == alphabet[a]) && (word[i + 1] == alphabet[b])) {
						for (short j = 0; j < len; j++) {
							word[j] = touppper(word[j]);
						}
						word[len] = '(';
						word[len + 1] = alphabet[a];
						word[len + 2] = alphabet[b];
						word[len + 3] = ')';
						word[len + 4] = '\0';
						break;
					}
				}
			}
		}
		out << word << ' ';
	}
	return 0;
}