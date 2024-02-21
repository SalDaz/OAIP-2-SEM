#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");

    // ��������� ����� fA � fB ��� ������
    FILE* fileA;

    if (fopen_s(&fileA, "fA.txt", "rt") != 0) 
    {
        cerr << "������ �������� ����� fA.txt" << std::endl;
        return 1;
    }

    FILE* fileB;
    if (fopen_s(&fileB, "fB.txt", "rt") != 0)
    {
        cerr << "������ �������� ����� fB.txt" << std::endl;
        fclose(fileA);
        return 1;
    }

    // ������ ���������� �������� � ������ ������� �� ������ ������
    int columnsA, columnsB;
    if (fscanf_s(fileA, "%d", &columnsA) != 1 || fscanf_s(fileB, "%d", &columnsB) != 1) 
    {
        cerr << "������ ������ ���������� �������� �� ������ fA.txt ��� fB.txt" << std::endl;
        fclose(fileA);
        fclose(fileB);
        return 1;
    }

    if (columnsA != columnsB) 
    {
        cerr << "���������� �������� � �������� �� ���������." << std::endl;
        fclose(fileA);
        fclose(fileB);
        return 1;
    }

    // ��������� ���� fC ��� ������
    FILE* fileC;
    if (fopen_s(&fileC, "fC.txt", "w") != 0) {
        cerr << "������ �������� ����� fC.txt ��� ������" << std::endl;
        fclose(fileA);
        fclose(fileB);
        return 1;
    }

    // ���������� ���������� �������� � ������� C
    fprintf(fileC, "%d", columnsA);

    // ������ ������� �� ������ � ���������� ������������ � ���� fC
    float elementA, elementB;
    while (fscanf_s(fileA, "%f", &elementA, sizeof(elementA)) == 1 &&
        fscanf_s(fileB, "%f", &elementB, sizeof(elementB)) == 1) 
    {
        float op = elementA * elementB;
        fprintf(fileC, " %f", op);

        // ���� ��������� ����� ������ � �����, ��������� �� ����� ������ � ������ A � B
        if (fgetc(fileA) == '\n' && fgetc(fileB) == '\n') 
        {
            fprintf(fileC, "\n");
        }
    }

    // ��������� ��� �����
    fclose(fileA);
    fclose(fileB);
    fclose(fileC);

    cout << "������������ ������ M1 � M2 �������� � ���� fC.txt" << std::endl;

    return 0;
}
