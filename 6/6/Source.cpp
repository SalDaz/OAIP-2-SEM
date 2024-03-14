#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

struct list {
	int number;
	list* next;
};

void insert(list*& p, int value);
int del(list*& p, int value);
void output(list* p);
void insertFile(list*& p);
void outputFile(list*& p);
void menu();

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice, value;
	list* first = nullptr;
	do {
		menu();
		cin >> choice;
		switch (choice) {
		case(1): {
			cout << "Введите целое число: "; cin >> value;
			insert(first, value);
			output(first);
			break;
		}
		case(2): {
			cout << "Введите число которое хотите удалить: "; cin >> value;
			cout << "Число: " << del(first, value) << " было удаленно из списка" << endl;
			output(first);
			break;
		}
		case(3): {
			insertFile(first);
			break;
		}
		case(4): {
			outputFile(first);
			break;
		}
		}
	} while (choice != 0);
}

void menu() {
	cout << "Сделайте выбор:" << endl;
	cout << " 1 - Ввод числа" << endl;
	cout << " 2 - Удаление числа из списка" << endl;
	cout << " 3 - Запись списка в файл" << endl;
	cout << " 4 - Чтение списка из файла" << endl;
	cout << " 5 - Нахождения суммы положительных чисел" << endl;
	cout << " 0 - Выход" << endl;
	cout << " Ваш выбор:";
}

void insert(list*& p, int value) {
	list* newP = new list;
	if (newP != NULL) {
		newP->number = value;
		newP->next = p;
		p = newP;
	}
	else {
		cout << "Операция дабовления неозможна.";
	}
}

void output(list* p) {
	if (p == NULL) {
		cout << "Список пуст.";
	}
	else {
		cout << "Список: ";
		while (p != NULL) {
			cout << "-->" << p->number;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void insertFile(list*& p) {
	ofstream file("file.txt");
	list* first = nullptr;
	list* temp = p;
	list buff;
	if (!file.is_open()) {
		cout << "Ошибка открытия файла для записи списка.";
		return;
	}
	if (p == NULL) {
		cout << "Список пуст.";
	}
	else {
		while (temp) {
			buff = *temp;
			file.write((char*)&buff, sizeof(list));
			temp = temp->next;
		}
	}
	file.close();
}

void outputFile(list*& p) {
	ifstream file("file.txt");
	list* first = nullptr;
	list temp;
	if (!file.is_open()) {
		cout << "Ошибка открытия файла для вывода списка.";
		return;
	}
	while (file.read((char*)&temp, sizeof(list))) {
		insert(first, temp.number);
	}
	file.close();
	p = first;
}

int del(list*& p, int value) {
	list* previos, * current, * temp;
	if (value == p->number) {
		temp = p;
		p = p->next;
		delete(temp);
		return value;
	}
	else {
		previos = p;
		current = p->next;
		while (current != NULL && current->number != value) {
			previos = current;
			current = current->next;
		}
		if (current != NULL) {
			temp = current;
			previos->next = current->next;
			delete(temp);
			return value;
		}
	}
	return 0;
}
