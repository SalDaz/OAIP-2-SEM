#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fstream fout("FILE1.txt");
	string srt;
	if (!fout.is_open()) {
		cout << "Ошибка открытия файла для изменения";
		return 0;
	}
	cout << "Введите строку со словами и цифрами через пробел: " << endl;
	getline(cin, srt);
	fout << srt << endl;
	fout.close();
	fstream fin("FILE1.txt");
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла для чтения";
		return 0;
	}
	char new_string[255];
	fin.getline(new_string, 255);
	int count = 0;
	cout << "Нечётные числа в строке: " << endl;
	int Numbers[99]{};
	for (int i = 0; i < sizeof(new_string); i++) {
		if (isdigit(new_string[i])) {
			Numbers[count] = int(new_string[i] - 48);
			count++;
		}
		else {
			if (Numbers[count - 1] % 2 == 1) {
				for (int j = 0; j < count; j++) {
					cout << Numbers[j];
				}
				cout << endl;
			}
			count = 0;
		}
	}
	return 0;
}