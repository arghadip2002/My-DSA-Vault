#include <iostream>
using namespace std;

class LinkedListNode
{
public:
    int data;
    LinkedListNode *next;

    // constructor
    LinkedListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// void insertAtHead(LinkedListNode *&head, int data)
// {
//     // new node created
//     LinkedListNode *temp = new LinkedListNode(data);
//     temp->next = head;
//     head = temp;
// }

void insertAtTail(LinkedListNode *&tail, int data)
{
    // new node created
    LinkedListNode *temp = new LinkedListNode(data);
    tail->next = temp;
    tail = tail->next;
}

void print(LinkedListNode *&head)
{
    LinkedListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // created a new node
    LinkedListNode *node1 = new LinkedListNode(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    // Head and Tail pointed to new Node
    LinkedListNode *head = node1;
    LinkedListNode *tail = node1;
    print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    insertAtTail(tail, 20);
    print(head);
}