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
        string date_of_birth; // �������� ��� �� string
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
            cout << "\n1.���� ������ � ���������� � ������ � ����\n";
            cout << "2.����� ������ �� �����\n";
            cout << "3.����� �� ���� ��������\n";
            cout << "4.�������� ������ �� ����\n";
            cout << "0.����� �� ���������\n\n";
            cout << "������� ����� ��������: ";
            cin >> choose;
            switch (choose)
            { 

                case(1):
                {
                    cout << endl << "������� ���������� ������� ��� �������� � ����: "; cin >> count;
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
                    cout << endl << "������� ��� �������� ������, �������� ������ �����: "; cin >> year;
                    find_year(year);
                    break;
                }
                case(4):
                {
                    cout << endl << "������� ����� ������ � ����, �������� ������ �������: "; cin >> count;
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
        ofstream fout("base.txt", ios::app);  // �������� ����� � ������ ����������
        if (fout.is_open()) {
            cin.ignore();
            for (int p = 0; p < size; p++) {
                cout << "�.�.�.: ";
                getline(cin, buf[current_size].fio);  // ���������� � ������� ������� ���������
                cout << "���� �������� (���� ����� ���): ";
                getline(cin, buf[current_size].date_of_birth);
                cout << "�����: ";
                getline(cin, buf[current_size].home);
                cout << "���: ";
                getline(cin, buf[current_size].sex);
                fout << current_size + 1 << " " << buf[current_size].fio << " " << buf[current_size].date_of_birth << " " << buf[current_size].home << " " << buf[current_size].sex << endl;
                current_size++;
            }
            fout.close();
            cout << endl << "������ ��������." << endl << endl;
        }
        else {
            cout << "������ �������� �����" << endl;
            return;
        }
    }

    void find_year(unsigned int year) 
    {
        cout << endl << "������, ���������� � " << year << ":" << endl;

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
            cout << "������ �������� �����" << endl;
            return;
        }

        fin.close();
    }

    void del(int number) {
        if (number < 1 || number > current_size) {
            cout << "�������� ����� ������." << endl;
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
                cout << "������ �������� �����." << endl;
                return;
            }
            if (rename("base_temp.txt", "base.txt") != 0) {
                cout << "������ �������������� �����." << endl;
                return;
            }

            current_size--;

            cout << endl << "������ ��� ������ �� ����." << endl << endl;
        }
        else {
            cout << "������ �������� �����." << endl;
            return;
        }
    }

    void output() 
    {
        cout << endl << "���������� � ���� �������:" << endl;

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
            cout << "������ �������� �����" << endl;
            return;
        }

        fin.close();
    }
    