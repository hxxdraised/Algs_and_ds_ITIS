#include <iostream>
using namespace std;

int sum(int *a, int size)
{
    int arr_sum = 0;
    for (int i = 0; i < size; i++)
        arr_sum += a[i];
    return arr_sum;
}

int main()
{
    int n;
    cin >> n;
    int array[n];
    int *arr_ptr = array;

    for (int i = 0; i < n; i++)
        cin >> array[i];

    cout << sum(arr_ptr, n) << endl;

    return 0;
}