/*
Refer to bubble_sort_optimized.cpp for detail discussion of space and time complexities.
*/

#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int size)
{
    cout << "Array : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubblesort(int arr[], int size)
{
    int n = size;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    printArray(arr, 8);
}

int main()
{
    int arr[8] = {6, 2, 4, 10, 25, 5, 8, 6};

    printArray(arr, 8); // printing the array
    bubblesort(arr, 8); // printing the sorted array
    return 0;
}