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

    cout << "уравнение x^2 + 4 * x - 2:" << endl;

    cout << "Начальное значение a: ";
    cin >> a1;

    cout << "Начальное значение b: ";
    cin >> b1;

    cout << "уравнение sin(x) + 0.1:" << endl;

    cout << "Начальное значение a: ";
    cin >> a2;

    cout << "Начальное значение b: ";
    cin >> b2;


    double (*first_pointer)(double) = first_function;
    double first_root = dichotomy(first_pointer, a1, b1, e);

    double (*second_pointer)(double) = second_function;
    double second_root = dichotomy(second_pointer, a2, b2, e);

    cout << "Корень уравнения x^2 + 4 * x - 2: " << first_root << endl;
    cout << "Корень уравнения sin(x) + 0.1: " << second_root << endl;

    return 0;
}