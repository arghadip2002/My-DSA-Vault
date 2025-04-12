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

void insertAtHead(LinkedListNode *&head, int data)
{
    // new node created
    LinkedListNode *temp = new LinkedListNode(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(LinkedListNode *&tail, int data)
{
    // new node created
    LinkedListNode *temp = new LinkedListNode(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtPosition(LinkedListNode *&head, LinkedListNode *&tail, int position, int data)
{
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    LinkedListNode *temp = head;
    int count = 1;

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    // new node created
    LinkedListNode *nodeToInsert = new LinkedListNode(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
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

    insertAtPosition(head, tail, 3, 100);
    print(head);

    cout << "Data of Head " << head->data << endl;
    cout << "Data of Tail " << tail->data << endl;
}