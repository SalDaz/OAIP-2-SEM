#include <iostream>
#include <Windows.h>
#include <string>
#define size 20
using namespace std;

enum Ejob {
	������ = 1, ��������, ��������, �����
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
		cout << endl << "�������� ��������: " << endl;
		cout << "1 - ���������� ���������" << endl;
		cout << "2 - ����� ���� ����������" << endl;
		cout << "3 - �������� ���������" << endl;
		cout << "4 - ���� ��������� �� ����� ������" << endl;
		cout << "0 - ����� �� ���������" << endl;
		cout << endl << "��� �����: "; cin >> choice;
		switch (choice) {
		case (1): {
			cout << endl << "������� ���������� �� ������ ��������?" << endl;
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
			cout << endl << "����� ���������, �������� �� ������ �������?" << endl;
			cin >> input;
			del(input);
			break;
		}
		case (4): {
			cout << endl << "������� ���������� � ����� ������ �� ������ ������:" << endl;
			cin >> input;
			find(input);
			break;
		}
		default: {
			cout << endl << "����������� ����, ������� ���������� �������� ��������." << endl;
			break;
		}
		case (0): {
			cout << "��������� ���������.";
			break;
		}
		}
	} while (choice != 0);
}

string job_output(Ejob job) {
	switch (job) {
	case ������:
		return "������";
	case ��������:
		return "��������";
	case ��������:
		return "��������";
	case �����:
		return "�����";
	default:
		return "������������ ���������";
	}
}

void adding(int count) {
	Ejob job;
	int input;
	int year, day, month;
	for (int i = 0; i < count; i++) {
		cout << "������� �.�.�. ���������: ";
		cin.ignore();
		getline(cin, info[i].fio);
		cout << "������� ���� �������� ���������(�� �� ����): "; cin >> day >> month >> year;
		if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2024) {
			cout << "�������� �������� ���� ��������. ����������, ��������� ����." << endl;
			return;
		}
		info[i].day_birth = day;
		info[i].month_birth = month;
		info[i].year_birth = year;
		cin.ignore();
		cout << "������� ���������� ���������: "; getline(cin, info[i].education);
		cout << "������� ������������ ���������: "; getline(cin, info[i].spec);
		do {
			cout << "������� ��������� ���������(1 - ������, 2 - ��������, 3 - ��������, 4 - �����): ";
			cin >> input;
			job = static_cast<Ejob>(input);
			info[i].job = job_output(job);// �������������� int � Ejob
		} while (job > 4 || job < 1);
		cout << "������� ����� ���������: "; cin >> info[i].wages;
		cout << "������� ���� ����������� ��������� �� ������(�� �� ����): "; cin >> day >> month >> year;
		if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2024) {
			cout << "�������� �������� ���� ����������� �� ������. ����������, ��������� ����." << endl;
			cin.ignore();
			return;
		}
		info[i].day_accept = day;
		info[i].month_accept = month;
		info[i].year_accept = year;
		number++;
	}
	cout << "������� ������������ ���� � ������� �� �� ����: "; cin >> day >> month >> year;
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
		cout << "���������� � ��������� " << i + 1 << endl <<
			"�.�.�: " << info[i].fio << endl <<
			"���� ��������: " << info[i].day_birth << " " << info[i].month_birth << " " << info[i].year_birth << endl <<
			"�����������: " << info[i].education << endl <<
			"�������������: " << info[i].spec << endl <<
			"���������: " << info[i].job << endl <<
			"�������� ���������: " << info[i].wages << endl <<
			"���� �������� ���������: " << info[i].day_accept << " " << info[i].month_accept << " " << info[i].year_accept << endl <<
			"����: " << info[i].year << " ���" << endl << endl;
	}
}

void del(int del) {
	for (int i = del - 1; i < number; i++) {
		info[i] = info[i + 1];
	};
	number--;
}

void find(int year_w) {
	cout << "��������� �� ������ " << year_w << " ��� � ������: " << endl;
	for (int i = 0; i < number; i++) {
		if (info[i].year >= year_w) {
			cout << "���������� � ��������� " << i + 1 << endl <<
				"�.�.�: " << info[i].fio << endl <<
				"���� ��������: " << info[i].day_birth << " " << info[i].month_birth << " " << info[i].year_birth << endl <<
				"�����������: " << info[i].education << endl <<
				"�������������: " << info[i].spec << endl <<
				"���������: " << info[i].job << endl <<
				"�������� ���������: " << info[i].wages << endl <<
				"���� �������� ���������: " << info[i].day_accept << " " << info[i].month_accept << " " << info[i].year_accept << endl <<
				"����: " << info[i].year << " ���" << endl << endl;
		}
	}
}