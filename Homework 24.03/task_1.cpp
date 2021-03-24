#include <iostream>
using namespace std;

struct MaxHeap
{
    int size = -1;
    int maxSize = 9;
    int array[10];

    int Parent(int i) { return (i - 1) / 2; }
    int LeftChild(int i) { return 2 * i + 1; }
    int RightChild(int i) { return 2 * i + 2; }

    void SiftUp(int i)
    {
        while ((i > 0) && (array[i] > array[Parent(i)]))
        {
            swap(array[i], array[Parent(i)]);
            i = Parent(i);
        }
    }
    void SiftDown(int i)
    {
        int maxIndex = i;
        if ((LeftChild(i) > maxIndex) && (LeftChild(i) < size))
            maxIndex = LeftChild(i);
        if ((LeftChild(i) > maxIndex) && (LeftChild(i) < size))
            maxIndex = LeftChild(i);
        if (maxIndex != i)
        {
            swap(array[i], array[maxIndex]);
            SiftDown(maxIndex);
        }
    }
    void Insert(int p)
    {
        if (size < maxSize)
        {
            size++;
            array[size] = p;
            SiftUp(size);
        }
    }
    int ExtractMax()
    {
        // Записываем 0 элемент в result
        // Меняем 0 элемент с элементом под номером size
        // Уменьшаем size
        // SiftDown(0)
        // return result
        int result = array[0];
        swap(array[0], array[size]);
        size--;
        SiftDown(0);
        return result;
    }
    int GetMax()
    {
        return array[0];
    }
    void print()
    {
        cout << "Heap: ";
        for (int i = 0; i <= size; i++)
            cout << array[i] << " ";
        cout << endl;
    }
};

void HeapSort(int *array, int size)
{
    MaxHeap *heap = new MaxHeap;
    for (int i = 0; i < size; i++)
    {
        heap->Insert(*(array + i));
    }
    for (int i = size - 1; i >= 0; i--)
    {
        array[i] = heap->ExtractMax();
    }
}

int main()
{
    auto *heap = new MaxHeap;
    heap->Insert(5);
    heap->Insert(10);
    heap->Insert(20);
    heap->Insert(30);
    heap->print();

    cout << heap->ExtractMax() << endl;
    heap->print();
    cout << heap->GetMax()<<endl;

    int sampleArr[5] = {3, 2, 20, 5, 4};
    HeapSort(&sampleArr[0], 5);
    cout << "Sorted: ";
    for (int i = 0; i < 5; i++)
    {
        cout << sampleArr[i] << " ";
    }
    cout << endl;

    return 0;
}
