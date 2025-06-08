#include <iostream>
using namespace std;

void heapify(int arr[], int size, int index)
{
    int parent = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (arr[parent] < arr[left] && left <= size)
    {
        parent = left;
    }

    if (arr[parent] < arr[right] && right <= size)
    {
        parent = right;
    }

    if (parent != index)
    {
        swap(arr[parent], arr[index]);
        heapify(arr, size, parent);
    }
}

void buildHeap(int arr[], int size)
{
    for (int i = size / 2; i > 0; i--)
    {
        heapify(arr, size, i);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void heapSort(int arr[], int size)
{

    while (size > 1)
    {
        int parent = 1;
        swap(arr[parent], arr[size]);
        size--;

        heapify(arr, size, parent);
    }
}

int main()
{
    int array[5] = {-1, 2, 9, 3, 7};
    // int array[8] = {-1, 53, 65, 45, 85, 95, 65, 98};

    int n = sizeof(array) / sizeof(array[0]) - 1;
    buildHeap(array, n);
    printArray(array, n);
    heapSort(array, n);
    printArray(array, n);
}