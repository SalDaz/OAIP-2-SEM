#include <iostream>
#include <cmath>

using namespace std;

double first_function(double x)
{
    return pow(x, 2) + 4 * x - 2;
}


double second_function(double x)
{
    return sin(x) + 0.1;
}

double dichotomy(double (*pointer)(double), double a, double b, double e)
{
    double x;

    do
    {
        x = (a + b) / 2;

        if (pointer(x) * pointer(a) <= 0)
        {
            b = x;
        }

        else
        {
            a = x;
        }

    } while (abs(a - b) > 2 * e);

    return x;

}

int main()
{
    setlocale(LC_ALL, "ru");

    double a1, b1, a2, b2, e = 0.001;

    cout << "��������� x^2 + 4 * x - 2:" << endl;

    cout << "��������� �������� a: ";
    cin >> a1;

    cout << "��������� �������� b: ";
    cin >> b1;

    cout << "��������� sin(x) + 0.1:" << endl;

    cout << "��������� �������� a: ";
    cin >> a2;

    cout << "��������� �������� b: ";
    cin >> b2;


    double (*first_pointer)(double) = first_function;
    double first_root = dichotomy(first_pointer, a1, b1, e);

    double (*second_pointer)(double) = second_function;
    double second_root = dichotomy(second_pointer, a2, b2, e);

    cout << "������ ��������� x^2 + 4 * x - 2: " << first_root << endl;
    cout << "������ ��������� sin(x) + 0.1: " << second_root << endl;

    return 0;
}