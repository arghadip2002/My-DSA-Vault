/*
This code is optimized for bubble sort. In case of best cases, when the array is sorted or no swap take place (after certain rounds/steps) in a particular round, then no more further operations take place and thus reducing the time complexity.

# Space Complexity : O(1)

# Time Compelxity :

1. Best Case - O(n2)
2. Average Case - O(n2)
3. Worst Case - O(n2)

# It is In-Place Sorting

# It is UnStable Sorting Algorithm

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

void selectionSort(int arr[], int size)
{
    int n = size;
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }

    printArray(arr, 8);
}

int main()
{
    int arr[8] = {6, 2, 4, 10, 25, 5, 8, 6};

    printArray(arr, 8);    // printing the array
    selectionSort(arr, 8); // printing the sorted array
    return 0;
}

// Notes :-

/*

What is In-Place Sorting?

An in-place sort is a sorting algorithm that sorts the data without requiring extra space proportional to the input size. This means the algorithm modifies the input data structure directly, rather than creating a separate copy of the data.

# Examples of In-Place Sorting Algorithms:

1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Heapsort
5. Quicksort

# Non-In-Place Sorting Algorithms:

1. Merge Sort: Requires (O(n)) extra space for merging.

-------------------------------------------------------------------------------------

What is Stable and Unstable Sorting Algorithm?

# Stable Sorting Algorithm - A stable sorting algorithm maintains the relative order of records with equal keys (or values). This means that if two elements are equal, they will appear in the same order in the sorted output as they appear in the input.

Examples of Stable Sorting Algorithms:

1. Bubble Sort
2. Insertion Sort
3. Merge Sort
4. Counting Sort

# Unstable sorting algorithm does not guarantee the preservation of the relative order of records with equal keys. This means that equal elements might not retain their original order after sorting.

Examples of Unstable Sorting Algorithms:

1. Quicksort
2. Heapsort
3. Selection Sort

*/
