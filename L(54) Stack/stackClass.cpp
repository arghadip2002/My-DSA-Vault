#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            top--;
        }
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "Array is Empty" << endl;
            return;
        }
        cout << "Top Element - " << arr[top] << endl;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print()
    {
        for (int point = 0; point <= top; point++)
        {
            cout << arr[point] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st(10);

    st.push(10);
    st.push(20);
    st.push(50);
    st.push(45);
    st.push(25);
    st.push(15);
    st.push(10);
    st.push(50);
    st.push(45);
    st.push(15);

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    st.peek();

    st.print();

    return 0;
}