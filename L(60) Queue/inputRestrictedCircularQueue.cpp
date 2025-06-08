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

    void popBack()
    {
        if (isEmpty())
        {
            return;
        }

        if (rare == 0)
        {
            rare = size - 1;
            counterR--;
        }
        else
        {
            rare--;
            counterR--;
        }
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

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.print();

    q.dequeue();

    q.print();

    q.popBack();

    q.print();

    q.enqueue(10);

    q.print();

    q.dequeue();

    q.print();

    return 0;
}