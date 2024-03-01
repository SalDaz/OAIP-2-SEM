    #include <iostream>
    #include <fstream>
    #include <string>
    #include <Windows.h>

using namespace std;

    void input(int size);
    void output();
    void del(int number);
    void find_year(unsigned int year);

    struct civilian {
        string fio;
        string date_of_birth; // Изменили тип на string
        string home;
        string sex;
    };

    civilian buf[10];
    int current_size = 0;

    int main() {


        setlocale(LC_ALL, "rus");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        int year;
        int choose, count;
        for (int i = 0; i < current_size; i++) {
            cout << i + 1 << " " << buf[i].fio << " " << buf[i].date_of_birth << " " << buf[i].home << " " << buf[i].sex << endl;
        }
        do {
            cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
            cout << "2.Вывод данных из файла\n";
            cout << "3.Поиск по году рождения\n";
            cout << "4.Удаление жителя из базы\n";
            cout << "0.Выход из программы\n\n";
            cout << "Введите номер операции: ";
            cin >> choose;
            switch (choose)
            { 

                case(1):
                {
                    cout << endl << "Введите количество жителей для внесения в базу: "; cin >> count;
                    input(count);
                    break;
                }
                case(2):
                {
                    output();
                    break;
                }
                case(3):
                {
                    cout << endl << "Введите год рождения жителя, которого хотите найти: "; cin >> year;
                    find_year(year);
                    break;
                }
                case(4):
                {
                    cout << endl << "Введите номер жителя в базе, которого хотите удалить: "; cin >> count;
                    del(count);
                    break;
                }
                case(0):
                {
                    exit(0);
                    break;
                }
            }

        } while (choose != 0);
        return 0;
    }

    void input(int size) {
        ofstream fout("base.txt", ios::app);  // Открытие файла в режиме дополнения
        if (fout.is_open()) {
            cin.ignore();
            for (int p = 0; p < size; p++) {
                cout << "Ф.И.О.: ";
                getline(cin, buf[current_size].fio);  // Сохранение в текущий элемент структуры
                cout << "Дата рождения (день месяц год): ";
                getline(cin, buf[current_size].date_of_birth);
                cout << "Город: ";
                getline(cin, buf[current_size].home);
                cout << "Пол: ";
                getline(cin, buf[current_size].sex);
                fout << current_size + 1 << " " << buf[current_size].fio << " " << buf[current_size].date_of_birth << " " << buf[current_size].home << " " << buf[current_size].sex << endl;
                current_size++;
            }
            fout.close();
            cout << endl << "Жители записаны." << endl << endl;
        }
        else {
            cout << "Ошибка открытия файла" << endl;
            return;
        }
    }

    void find_year(unsigned int year) 
    {
        cout << endl << "Жители, родившиеся в " << year << ":" << endl;

        ifstream fin("base.txt");
        if (fin.is_open()) {
            string line;
            while (getline(fin, line)) {
                size_t pos = line.find(to_string(year));
                if (pos != string::npos) {
                    cout << line << endl;
                }
            }
        }
        else {
            cout << "Ошибка открытия файла" << endl;
            return;
        }

        fin.close();
    }

    void del(int number) {
        if (number < 1 || number > current_size) {
            cout << "Неверный номер жителя." << endl;
            return;
        }

        ifstream fin("base.txt");
        ofstream fout("base_temp.txt");
        if (fin.is_open() && fout.is_open()) {
            string line;
            int count = 0;
            while (getline(fin, line)) {
                count++;
                if (count != number) {
                    fout << line << endl;
                }
            }
            fin.close();
            fout.close();

            if (remove("base.txt") != 0) {
                cout << "Ошибка удаления файла." << endl;
                return;
            }
            if (rename("base_temp.txt", "base.txt") != 0) {
                cout << "Ошибка переименования файла." << endl;
                return;
            }

            current_size--;

            cout << endl << "Житель был удален из базы." << endl << endl;
        }
        else {
            cout << "Ошибка открытия файла." << endl;
            return;
        }
    }

    void output() 
    {
        cout << endl << "Информация о всех жителях:" << endl;

        ifstream fin("base.txt");
        if (fin.is_open()) 
        {
            string line;
            while (getline(fin, line)) 
            {
                cout << line << endl;
            }
        }
        else
        {
            cout << "Ошибка открытия файла" << endl;
            return;
        }

        fin.close();
    }
    