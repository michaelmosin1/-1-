#include <iostream>
#include <fstream>


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


short length(char massive[]) {
	short leng = 0;
	while (massive[leng] != '\0') {
		leng++;
	}
	return leng;
}


bool has_three_same(char massive[]) {
	short len = length(massive);
	for (short a = 0; a < len-1; a++) {
		short count = 1;
		for (short b = a + 1; b < len; b++) {
			if (massive[a] == massive[b]) {
				count++;
				if (count == 3) {
					return true;
				}
			}
		}
	}
	return false;
}


bool strcompare(char word1[], char word2[]) {
	if (length(word1) == length(word2)) {
		for (short a = 0; a < length(word1); a++) {
			if (word1[a] != word2[a]) return false;
		}
		return true;
	}
	else return false;
}


int main() {
	setlocale(LC_ALL, "Russian");
	std::ifstream file_in("input.txt");
	char words_massive[2000][101] = {};
	short N;
	short words_in_massive = 0;
	std::cout << "Please input N:" << std::endl;
	std::cin >> N;
	while (!file_in.eof()) {
		char word[101] = {};
		file_in >> word;
		word_processing(word);
		if (has_three_same(word) && (words_in_massive < N)) {
			bool duplicate = false;
			for (short a = 0; a < words_in_massive; a++) {
				if (strcompare(word, words_massive[a])) duplicate = true;
			}
			if (!duplicate) {
				short a = 0;
				while (word[a] != '\0') {
					words_massive[words_in_massive][a] = word[a];
					a++;
				}
				words_massive[words_in_massive][a] = '\0';
				words_in_massive++;
			}
		}
		if (words_in_massive == N) { // sorting
			words_in_massive++;
			for (short a = 0; a < N; a++) {
				for (short b = a + 1; b < N; b++) {
					if (length(words_massive[b]) < length(words_massive[a])) {
						std::swap(words_massive[b], words_massive[a]);
					}
				}
			}
		}
		if (has_three_same(word) && (words_in_massive > N)) {
			bool duplicate = false;
			for (short a = 0; a < N; a++) {
				if (strcompare(word, words_massive[a])) duplicate = true;
			}
			if (!duplicate) {
				for (short a = 0; a < N; a++) {
					if (strcompare(words_massive[a - 1], word)) break;
					else if (length(word) < length(words_massive[a])) {
						for (short c = N - 1; c > a; c--) {
							short d = 0;
							while (words_massive[c - 1][d] != '\0') {
								words_massive[c][d] = words_massive[c - 1][d];
								d++;
							}
							words_massive[c][d] = '\0';
						}
						short b = 0;
						while (word[b] != '\0') {
							words_massive[a][b] = word[b];
							b++;
						}
						words_massive[a][b] = '\0';
					}
					break;
				}
			}
		}
	}
	for (short a = 0; a < N; a++) {
		std::cout << a << ' ' << words_massive[a] << std::endl;
	}
	//std::ofstream out("output.txt"); //запись в файл - раскомментировать, если удобно вывести текст в файл
	//for (short a = 0; a < N; a++) {
	//	out << words_massive[a] << std::endl;
	//}
	//out.close();
	return 0;
}