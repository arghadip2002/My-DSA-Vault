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

int binarySearch(int arr[], int size, int key)
{
    // Sorting the array (Binary Search Works only on Sorted Arrays)
    sort(arr, arr + size);

    // Printing the Sorted Array
    cout << "Sorted Array :" << " ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // BINARY SEARCH :-
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2; // mid = (start+end)/2 ; but for optimisation it is done. so that (start+end) does not exceeds the value of INT_MAX in any case.

    while (start <= end)
    {
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return -1;
}

int main()
{
    int even[8] = {1, 5, 9, 3, 4, 6, 2, 8};
    int odd[5] = {4, 6, 8, 2, 4};

    printArray(even, 8);                   // printing the array
    int result = binarySearch(even, 8, 5); // printing the sorted array and returning the index of the key
    cout << "The 9 is at index : " << result << endl;

    printArray(odd, 5);                    // printing the array
    int result2 = binarySearch(odd, 5, 8); // printing the sorted array and returning the index of the key
    cout << "The 8 is at index : " << result2;

    return 0;
}