#include <iostream>
#include <string>
using namespace std;

int binarySearch(int a[], int fromIndex, int toIndex, int key, bool last)
{
    int low = fromIndex;
    int high = toIndex - 1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int midVal = a[mid];

        if (midVal < key || (last && midVal == key))
            low = mid + 1;
        else if (midVal > key || (!last && midVal == key))
            high = mid - 1;
    }
    return last ? high : low;
}

int main()
{
    int n, m;
    int key;
    int index;
    int indexl;

    cout << "N: ";
    cin >> n;
    cout << "M: ";
    cin >> m;

    int array[n * m];
    cout << "Write matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> array[i * n + j];

    for (int i = 0; i < n * m; i++)
        cout << array[i] << " | ";
    cout << "size: " << n * m;
    cout << "\nWrite number: ";
    cin >> key;

    index = binarySearch(array, 0, n * m, key, false);
    index = (array[index] == key) ? index : -1;

    if (index >= 0)
        cout << "Number exist in matrix(index: " << index << ")" << endl;
    else
        cout << "No such number in matrix" << endl;

    return 0;
}