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
    int size;
    int array[size];
    int key;
    int indexf;
    int indexl;
    string rawArr;

    cout << "Write array: ";
    cin >> rawArr;

    size = rawArr.size();
    for (int i = 0; i < size; i++)
    {
        array[i] = ((int)rawArr[i] - 48);
    }
    for (int i = 0; i < size; i++)
        cout << array[i] << " | ";
    cout << "size: " << size;
    cout << "\nWrite number: ";
    cin >> key;

    indexf = binarySearch(array, 0, size, key, false);
    indexf = (array[indexf] == key) ? indexf : -1;
    indexl = (indexf == -1) ? -1 :binarySearch(array, 0, size, key, true);

    if (indexf >= 0)
    {
        cout << "first index: " << indexf << endl;
        cout << "last index: " << indexl << endl;
    }
    else
        cout << "No such number in array\n\n";

    return 0;
}