#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int neg, pos, num, K;
    FILE* f;
    FILE* g;

    printf("������� ���������� ������������� �����: ");
    scanf_s("%d", &neg);

    printf("������� ���������� ������������� �����: ");
    scanf_s("%d", &pos);

    printf("������� ����� K: ");
    scanf_s("%d", &K);

    fopen_s(&f, "f.txt", "w");
        for (int j = 0; j < neg; j++) {
            fprintf(f, " %d", (rand() % 90 + 10));
        }
        for (int j = 0; j < pos; j++) {
            fprintf(f, " %d", -(rand() % 90 + 10));
        }

        fclose(f);
        fopen_s(&f, "f.txt", "r");
        fopen_s(&g, "g.txt", "w");

        for (int j = 0; j < neg+pos; j++)
        {
            fscanf_s(f, "%d", &num);
            if (num % K == 0) 
            {
                fprintf(g, " %d", num);
            }
        }

    fclose(f);
    fclose(g);

    cout << "����� �������� � ����� g.txt" << endl;

    return 0;
}


// �������� ����������������� � 2 ���������