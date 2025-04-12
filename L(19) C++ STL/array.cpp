#include <iostream>
#include <array>

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

int main()
{
    int arr[3] = {1, 5, 4}; // Normal static array

    array<int, 3> a = {1, 6, 80};
    printArray(arr, 3);

    int size = a.size();
    cout << "Array : ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Array at index 2 : " << a.at(2) << endl;
    cout << "is array empty ? " << a.empty() << endl;
    cout << "Array at index 1 : " << a.front() << endl;
    cout << "Array at index last : " << a.back() << endl;
}