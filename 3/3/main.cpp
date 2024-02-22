#include <iostream>
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	char string[255];
	fstream fin("FILE1.txt");
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла для чтения.";
		return 0;
	}
	fstream fout("FILE2.txt");
	if (!fout.is_open()) {
		cout << "Ошибка открытия файла для записи.";
		return 0;
	}
	for (int i = 0; i < 10; i++) {
		fin.getline(string, 255);
		if (i % 2 == 1) {
			fout << string << endl;
		}
	}
	fin.close();
	fout.close();
	return 0;
}