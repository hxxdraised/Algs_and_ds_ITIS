#include <iostream>
using namespace std;

void qs(int *s_arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = s_arr[(left + right) / 2];
        do
        {
            while (s_arr[left] < middle)
                left++;
            while (s_arr[right] > middle)
                right--;
            if (left <= right)
            {
                int tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qs(s_arr, first, right);
        qs(s_arr, left, last);
    }
}


int main()
{
    int n;
    cin >> n;
    int *array = new int[n];

    for (int i = 0; i < n; i++)
        cin >> array[i];

    qs(array, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    return 0;
}