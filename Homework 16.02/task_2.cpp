#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a, b, c, x1, x2;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    double disc = b * b - 4 * a * c;
    if (disc > 0)
    {

        x1 = (-1 * b + sqrt(disc)) / (2 * a);
        x2 = (-1 * b - sqrt(disc)) / (2 * a);
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (disc == 0)
    {
        x1 = (-1 * b + sqrt(disc)) / (2 * a);
        cout << "x = " << x1 << endl;
    }
    else
        cout << "Корней нет" << endl;

    return 0;
}