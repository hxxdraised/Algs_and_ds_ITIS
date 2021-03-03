#include <iostream>
using namespace std;

int main()
{
    int x, buff = 1, p = 0;

    cin >> x;
    if (x > 1)
    {
        while (true)
        {
            if (buff >= x)
                break;
            p++;
            buff *= 2;
        }
        cout << p - 1 << endl;
    }
    else
        cout << "error" << endl;

    return 0;
}