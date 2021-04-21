#include <iostream>
#include <string>
using namespace std;

int binSearch(int arr[], int left, int right, int key)
{
    int midd = 0;
    while (1)
    {
        midd = (left + right) / 2;

        if (key < arr[midd])
            right = midd - 1;
        else if (key > arr[midd])
            left = midd + 1;
        else
            return midd;

        if (left > right)
            return -1;
    }
}

int main()
{
    int size;
    int array[size];
    int key = 0;
    int index = 0;
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

    cout << "\nWrite number: ";
    cin >> key;

    index = binSearch(array, 0, size, key);

    if (index >= 0)
        cout << "index: " << index << "\n\n";
    else
        cout << "No such number in array\n\n";

    return 0;
}