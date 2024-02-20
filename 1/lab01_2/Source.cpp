#include <iostream>
// ПРИНЯТИЕ НЕОГРАНИЧ КОЛ-ВА АРГУМЕНТОВ
#include <cstdarg>

using namespace std;

int fmin(int count, ...) 
{
    va_list args;
    va_start(args, count);

    int min = va_arg(args, int);

    for (int i = 1; i < count; ++i) 
    {
        int num = va_arg(args, int);

        if (num < min)
        {
            min = num;
        }
    }

    va_end(args);

    return min;
}


int main() 
{
    setlocale(LC_ALL,"RU");
    int first_min = fmin(3, 5, 2, 7);
    int second_min = fmin(4, 10, 6, 3, 9);
    int third_min = fmin(5, 8, 4, 1, 7, 2);

    cout << "Минимальные значения:" << endl;
    cout << "Первого обращения: " << first_min << endl;
    cout << "Второго обращения: " << second_min << endl;
    cout << "Третьего обращения: " << third_min << endl;

    return 0;
}