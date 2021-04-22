#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int lower(int *a, int size, int val)
{
    int c = 0;
    for (int i = 0; i < size; i++)
        if (a[i] < val)
            c++;
    return c;
}

int higher(int *a, int size, int val)
{
    int c = 0;
    for (int i = 0; i < size; i++)
        if (a[i] > val)
            c++;
    return c;
}

int medium(int *a, int size)
{
    int L = 0, R = INT_MAX, m;

    while (L < R)
    {
        m = (L + R) / 2;
        if (lower(a, size, m) < higher(a, size, m))
            L = m;
        else if (lower(a, size, m) > higher(a, size, m))
            R = m;
        else if (lower(a, size, m) == higher(a, size, m))
            break;
    }
    return m;
}

int main()
{

    int n, m;
    cout << "N: ";
    cin >> n;
    cout << "M: ";
    cin >> m;
    int array[n * m];

    for (int i = 0; i < n * m; i++)
        cin >> array[i];
    cout << medium(array, n * m) << endl;
}