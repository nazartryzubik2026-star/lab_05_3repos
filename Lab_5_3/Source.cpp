#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Прототип функції
double s(const double x);

int main()
{
    double tp, tk;
    int n;

    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n = ";  cin >> n;

    if (n <= 0)
    {
        cout << "n має бути додатним!" << endl;
        return 1;
    }

    double dt = (tk - tp) / n;

    // Шапка таблиці
    cout << fixed;
    cout << "-----------------------------------" << endl;
    cout << "|" << setw(12) << "t" << "   |" << setw(15) << "z" << "   |" << endl;
    cout << "-----------------------------------" << endl;

    for (int i = 0; i <= n; i++)
    {
        double t = tp + i * dt;
        double z = s(t * t + 1) + 2 * pow(s(1 - t), 2) + s(1);

        cout << "|" << setw(12) << setprecision(3) << t << "   |"
            << setw(15) << setprecision(6) << z << "   |" << endl;
    }
    cout << "-----------------------------------" << endl;

    return 0;
}

// Реалізація функції s(x) для Варіанту 16
double s(const double x)
{
    if (fabs(x) > 1)
    {
        // Для |x| > 1: (cos^2(x) + 1) / e^x
        return (cos(x) * cos(x) + 1.0) / exp(x);
    }
    else
    {
        // Для |x| <= 1: сума ряду Тейлора від k = 0 до 4
        double S = x; // Перший доданок при k = 0: x
        double a = x; // Поточний доданок

        for (int k = 1; k <= 4; k++)
        {
            // Рекурентне співвідношення: R = x^2 / (2k * (2k + 1))
            double R = (x * x) / ((2.0 * k) * (2.0 * k + 1.0));
            a *= R;
            S += a;
        }
        return S;
    }
}