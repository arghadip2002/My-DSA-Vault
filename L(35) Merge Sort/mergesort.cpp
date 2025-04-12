#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // Copy values to new arrays
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[s + i];
    }
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mid + 1 + i];
    }

    // Merge the two sorted arrays
    int index1 = 0;
    int index2 = 0;
    int mainArrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] <= second[index2])
        {
            arr[mainArrayIndex] = first[index1];
            index1++;
        }
        else
        {
            arr[mainArrayIndex] = second[index2];
            index2++;
        }
        mainArrayIndex++;
    }

    // Copy remaining elements of first array
    while (index1 < len1)
    {
        arr[mainArrayIndex] = first[index1];
        index1++;
        mainArrayIndex++;
    }

    // Copy remaining elements of second array
    while (index2 < len2)
    {
        arr[mainArrayIndex] = second[index2];
        index2++;
        mainArrayIndex++;
    }

    delete[] first;
    delete[] second;
}

void mergesort(int *arr, int s, int e)
{
    // Base case
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    // Left part to be sorted
    mergesort(arr, s, mid);

    // Right part to be sorted
    mergesort(arr, mid + 1, e);

    // Merge
    merge(arr, s, e);
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

    mergesort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
