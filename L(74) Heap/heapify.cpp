#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index 'i'
// 'n' is the size of the heap
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i;      // Left child
    int right = 2 * i + 1; // Right child

    // Check if left child is larger than root
    if (left <= n && arr[left] > arr[largest])
        largest = left;

    // Check if right child is larger than the largest so far
    if (right <= n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to build a max heap
void buildHeap(int arr[], int n)
{
    // Start heapifying from the last non-leaf node
    for (int i = n / 2; i > 0; i--)
        heapify(arr, n, i);
}

// Function to print the heap
void printArray(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int array[8] = {-1, 53, 65, 45, 85, 95, 65, 98};
    int n = 7;
    buildHeap(array, n);
    printArray(array, n);
}