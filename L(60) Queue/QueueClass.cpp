#include <iostream>
using namespace std;

class Queue
{
public:
    int front;
    int rare;
    int *arr;
    int size;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rare = -1;
    }

    void enqueue(int data)
    {
        // if (rare == front)
        if (isEmpty())
        {
            rare = front = -1;
        }

        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        rare++;
        arr[rare] = data;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        front++;
    }

    void print()
    {
        if (rare == front)
        {
            cout << "Array is Empty" << endl;
            return;
        }
        int point = front + 1;
        for (; point <= rare; point++)
        {
            cout << arr[point] << " ";
        }
        cout << endl;
    }

    bool isFull()
    {
        if (rare == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if (front == rare)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(50);
    q.enqueue(40);

    q.dequeue();
    q.dequeue();
    // q.dequeue();

    q.enqueue(100);
    // q.enqueue(35);

    // q.dequeue();
    // q.dequeue();
    // q.dequeue();

    q.print();

    return 0;
}