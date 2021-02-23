#include <iostream>
using namespace std;


int *merge(int *a, int size_1, int *b, int size_2)
{
    int *arr = new int[size_1 + size_2];
    for (int i = 0; i < size_1; i++)
        arr[i] = a[i];
    for (int i = 0; i < size_2; i++)
        arr[size_1 + i] = b[i];
    return arr;
}


int main()
{
    int n, m;
    cin >> n;
    int *array_1 = new int[n];

    for (int i = 0; i < n; i++)
        cin >> array_1[i];

    cin >> m;
    int *array_2 = new int[n];

    for (int i = 0; i < m; i++)
        cin >> array_2[i];

    
    int *new_arr = merge(array_1, n, array_2, m);

    for (int i = 0; i < (n + m); i++)
        cout << new_arr[i] << " ";

    delete(array_1);
    delete(array_2);
    delete(new_arr);
    return 0;
}