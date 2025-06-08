#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> maxHeap;                            // Default max heap
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap

    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(20);

    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);

    cout << "Max Heap Top: " << maxHeap.top() << endl; // Output: 20
    cout << "Min Heap Top: " << minHeap.top() << endl; // Output: 5

    return 0;
}

// Priority Queue always creates a Max Heap.