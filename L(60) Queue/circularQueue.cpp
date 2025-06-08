#include <iostream>
using namespace std;

class CQueue
{
public:
    int front;
    int rare;
    int *arr;
    int size;
    int counterR;
    int counterF;

    CQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rare = -1;
        counterF = counterR = 0;
    }

    void enqueue(int data)
    {
        if (isEmpty())
        {
            rare = front = -1;
        }

        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        if (rare == size - 1)
        {
            rare = -1;
        }

        rare++;
        arr[rare] = data;
        counterR++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }

        if (front == size - 1)
        {
            front = -1;
        }

        front++;
        counterF++;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Array is Empty" << endl;
            return;
        }
        int pointF = counterF;
        for (; pointF < counterR; pointF++)
        {
            cout << arr[pointF % (size)] << " ";
        }
        cout << endl;
    }

    bool isFull()
    {
        if ((rare == size - 1 && front == -1) || (front == rare && counterR > counterF))
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
        if (front == rare && counterR == counterF)
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
    CQueue q(5);
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
    q.enqueue(100);

    q.dequeue();
    q.dequeue();

    q.enqueue(100);
    q.enqueue(100);
    q.enqueue(100);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(10);
    q.enqueue(00);
    q.enqueue(1002);

    // q.dequeue();
    // q.dequeue();
    // q.dequeue();

    q.print();

    return 0;
}