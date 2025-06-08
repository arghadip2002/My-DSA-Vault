#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    // Place pivot at right position
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    // Taking care of the left and right part of pivotIndex
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        { // Using <= to ensure stability
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);

    // Sort left part
    quickSort(arr, s, p - 1);
    // Sort right part
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[10] = {2, 1, 58, 4, 65, 14, 1, 5, 4, 6};
    int n = 10;

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
