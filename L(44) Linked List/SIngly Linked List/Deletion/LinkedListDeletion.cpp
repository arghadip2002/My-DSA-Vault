#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~node()
    {
        // if (this->next != NULL)
        // {
        //     cout << "inside if called" << endl;
        //     delete next;
        //     this->next = NULL;
        // }
        cout << "Node with data " << this->data << " is deleted." << endl;
    }
};

void insertAtHead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(node *&tail, int data)
{
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(node *&head, node *&tail, int position, int data)
{
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    node *temp = head;
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

    node *nodeToInsert = new node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteAtPosition(node *&head, node *&tail, int position)
{
    if (position == 1)
    {
        node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    node *temp = head;
    node *prev = head;
    int count = 1;

    while (count < position)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    prev->next = temp->next;

    if (temp->next == NULL)
    {
        tail = prev;
    }

    temp->next = NULL;
    delete temp;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // CREATING THE FIRST NODE
    node *node1 = new node(10);

    // Head and Tail pointed to new Node
    node *head = node1;
    node *tail = node1;

    print(head);

    insertAtHead(head, 50);
    print(head);

    insertAtHead(head, 20);
    print(head);

    insertAtTail(tail, 200);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(head, tail, 6, 150);
    print(head);

    insertAtPosition(head, tail, 1, 750);
    print(head);

    insertAtPosition(head, tail, 5, 800);
    print(head);

    deleteAtPosition(head, tail, 5);
    print(head);

    deleteAtPosition(head, tail, 1);
    print(head);

    deleteAtPosition(head, tail, 6);
    print(head);

    cout << "Head data - " << head->data << " and Tail data - " << tail->data << endl;

    return 0;
}