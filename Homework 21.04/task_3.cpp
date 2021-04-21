#include <iostream>
#include <string>
using namespace std;

int binarySearch(int *a, int size, int key)
{
    int L = 0;
    int R = size;
    int med;

    while (L < R)
    {
        med = (L + R) / 2;
        if (key > a[med])
            L = med;
        if (key < a[med])
            R = med;
        if ((a[med] == key) || (R - L < 2))
            break;
    }
    if ((key - a[L]) < (a[R] - key))
        return L;
    return R;
}

int main()
{
    int n;
    int index;
    int size;

    cout << "\nWrite number: ";
    cin >> n;
    size = n / 2 + 2;
    int array[size];
    for (int i = 0; i< size; i++)
        array[i] = i*i;

    index = binarySearch(array, size, n);
    cout << "sqrt: " << index << endl;

    return 0;
}