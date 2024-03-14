#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#define SIZE 5
using namespace std;

union Data {
    char surname[50];
    char examName[50];
    char examDate[50];
};

struct Data_s {
    Data data;
};

struct Data_s data_s[SIZE];


void writeToFile(string filename, int count) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для записи.";
        return;
    }
    cout << "Введите Фамилию преподавателя: "; cin >> data_s[count].data.surname;
    file << data_s[count].data.surname << " ";
    cout << "Введите название экзамена: "; cin >> data_s[count].data.examName;
    file << data_s[count].data.examName << " ";
    cout << "Введите дату экзамена: "; cin >> data_s[count].data.examDate;
    file << data_s[count].data.examDate << " " << endl;
    file.close();
}

void readFromFile(string filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void searchBySurname(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для записи.";
        return;
    }
    string line;
    string surname;
    cout << "Введите фамилию преподавателя: ";
    cin.ignore();
    getline(cin, surname);
    while (getline(file, line)) {
        if (line.find(surname) != string::npos) {
            cout << line << endl;
        }
    }
    file.close();
}

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    int count = 0;
    string filename = "data.txt";
    do {
        cout << endl << "1. Ввод экзамена" << endl;
        cout << "2. Выводи всех экзаменов" << endl;
        cout << "3. Поиск экзамена по фамилии" << endl;
        cout << "0. Выход из программы" << endl;
        cout << "Введите ваш выбор: " << endl;
        cin >> choice;
        switch (choice) {
        case(1): {
            writeToFile(filename, count);
            break;
        }
        case(2): {
            cout << endl << "Данные из файла:" << endl;
            readFromFile(filename);
            break;
        }
        case(3): {
            searchBySurname(filename);
            break;
        }
        default: {
            cout << "Ошибка, попробуйте ещё раз.";
            break;
        }
        case (0): return 0;
        }
    } while (choice != 0);

    return 0;
}
