#include <iostream>
#include <Windows.h>
#include <string>
#define size 20
using namespace std;

enum Ejob {
	интерн = 1, работник, менеджер, глава
};

string job_output(Ejob job);
void adding(int count);
void output();
void del(int del);
void find(int year_w);

struct INFO {
	string fio;
	unsigned int day_birth : 5;
	unsigned int month_birth : 4;
	unsigned int year_birth : 12;
	string education;
	string spec;
	string job;
	unsigned int wages;
	unsigned int day_accept : 5;
	unsigned int month_accept : 4;
	unsigned int year_accept : 12;
	unsigned int year = 0;
};


struct INFO info[size];

int number = 0;

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	int input;
	do {
		cout << endl << "Выберите действие: " << endl;
		cout << "1 - Добавление работника" << endl;
		cout << "2 - Вывод всех работников" << endl;
		cout << "3 - Удаление работника" << endl;
		cout << "4 - Поск работника по стажу работы" << endl;
		cout << "0 - Выход из программы" << endl;
		cout << endl << "Ваш выбор: "; cin >> choice;
		switch (choice) {
		case (1): {
			cout << endl << "Сколько работников вы зотите добавить?" << endl;
			cin >> input;
			adding(input);
			break;
		}
		case (2): {
			cout << endl;
			output();
			break;
		}
		case (3): {
			output();
			cout << endl << "Номер работника, которого вы хотите удалить?" << endl;
			cin >> input;
			del(input);
			break;
		}
		case (4): {
			cout << endl << "Введите работников с каким стажем вы хотите видеть:" << endl;
			cin >> input;
			find(input);
			break;
		}
		default: {
			cout << endl << "Нправильный ввод, введите правильное значение действия." << endl;
			break;
		}
		case (0): {
			cout << "Программа завершена.";
			break;
		}
		}
	} while (choice != 0);
}

string job_output(Ejob job) {
	switch (job) {
	case интерн:
		return "Интерн";
	case работник:
		return "Работник";
	case менеджер:
		return "Менеджер";
	case глава:
		return "Глава";
	default:
		return "Некорректная должность";
	}
}

void adding(int count) {
	Ejob job;
	int input;
	int year, day, month;
	for (int i = 0; i < count; i++) {
		cout << "Введите Ф.И.О. работника: ";
		cin.ignore();
		getline(cin, info[i].fio);
		cout << "Введите дату рождения работника(ДД ММ ГГГГ): "; cin >> day >> month >> year;
		if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2024) {
			cout << "Неверные значения даты рождения. Пожалуйста, повторите ввод." << endl;
			return;
		}
		info[i].day_birth = day;
		info[i].month_birth = month;
		info[i].year_birth = year;
		cin.ignore();
		cout << "Введите обазование работника: "; getline(cin, info[i].education);
		cout << "Введите спицальность работника: "; getline(cin, info[i].spec);
		do {
			cout << "Введите должность работника(1 - интерн, 2 - работник, 3 - менеджер, 4 - глава): ";
			cin >> input;
			job = static_cast<Ejob>(input);
			info[i].job = job_output(job);// преобразование int в Ejob
		} while (job > 4 || job < 1);
		cout << "Введите оклад работника: "; cin >> info[i].wages;
		cout << "Введите дату поступления работника на работу(ДД ММ ГГГГ): "; cin >> day >> month >> year;
		if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2024) {
			cout << "Неверные значения даты поступления на работу. Пожалуйста, повторите ввод." << endl;
			cin.ignore();
			return;
		}
		info[i].day_accept = day;
		info[i].month_accept = month;
		info[i].year_accept = year;
		number++;
	}
	cout << "Введите сегодняюшнюю дату в формате ДД ММ ГГГГ: "; cin >> day >> month >> year;
	for (int i = 0; i < number; i++) {
		if (info[i].year_accept == year) {
			info[i].year = 0;
		}
		else {
			for (; year > info[i].year_accept; year--) info[i].year++;
		}
	}
}

void output() {
	for (int i = 0; i < number; i++) {
		cout << "Информация о работнике " << i + 1 << endl <<
			"Ф.И.О: " << info[i].fio << endl <<
			"Дата рождения: " << info[i].day_birth << " " << info[i].month_birth << " " << info[i].year_birth << endl <<
			"Образование: " << info[i].education << endl <<
			"Специальность: " << info[i].spec << endl <<
			"Должность: " << info[i].job << endl <<
			"Зарплата работника: " << info[i].wages << endl <<
			"Дата принятия работника: " << info[i].day_accept << " " << info[i].month_accept << " " << info[i].year_accept << endl <<
			"Стаж: " << info[i].year << " лет" << endl << endl;
	}
}

void del(int del) {
	for (int i = del - 1; i < number; i++) {
		info[i] = info[i + 1];
	};
	number--;
}

void find(int year_w) {
	cout << "Работники со стажем " << year_w << " лет и больше: " << endl;
	for (int i = 0; i < number; i++) {
		if (info[i].year >= year_w) {
			cout << "Информация о работнике " << i + 1 << endl <<
				"Ф.И.О: " << info[i].fio << endl <<
				"Дата рождения: " << info[i].day_birth << " " << info[i].month_birth << " " << info[i].year_birth << endl <<
				"Образование: " << info[i].education << endl <<
				"Специальность: " << info[i].spec << endl <<
				"Должность: " << info[i].job << endl <<
				"Зарплата работника: " << info[i].wages << endl <<
				"Дата принятия работника: " << info[i].day_accept << " " << info[i].month_accept << " " << info[i].year_accept << endl <<
				"Стаж: " << info[i].year << " лет" << endl << endl;
		}
	}
}