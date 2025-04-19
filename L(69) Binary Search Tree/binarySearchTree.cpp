#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *insertIntoBST(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }

    if (data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeInput(node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter the next node : ";
        cin >> data;
    }
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

bool search(node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == data)
    {
        return true;
    }

    if (data > root->data)
    {
        return search(root->right, data);
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
}

// int min(node *root)
// {
//     node *temp = root;
//     if (temp->left == NULL)
//     {
//         return temp->data;
//     }
//     else
//     {
//         return min(temp->left);
//     }
// }

node *min(node *root)
{
    node *temp = root;
    if (temp->left == NULL)
    {
        return temp; // Return the address of the minimum node.
    }
    else
    {
        return min(temp->left); // Continue recursion.
    }
}

// int max(node *root)
// {
//     node *temp = root;
//     if (temp->right == NULL)
//     {
//         return temp->data;
//     }
//     else
//     {
//         return max(temp->right);
//     }
// }

node *max(node *root)
{
    node *temp = root;
    if (temp->right == NULL)
    {
        return temp;
    }
    else
    {
        return max(temp->right);
    }
}

bool searchIteratively(node *root, int data)
{
    node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return true;
        }
        else
        {
            if (data > temp->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
    }
    return false;
}

node *deleteFromBST(node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {
        // with 0 child
        if (root->right == NULL && root->left == NULL)
        {
            delete root;
            return NULL;
        }

        // with 1 child
        else if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // with 2 child
        else
        {
            int mini = min(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    else if (val > root->data)
    {
        root->right = deleteFromBST(root->right, val);
    }
    else
    {
        root->left = deleteFromBST(root->left, val);
    }
}

int main()
{
    node *root = NULL;

    //  50 20 70 10 30 90 110 -1
    cout << "Entre the Data to Create BST: ";
    takeInput(root);

    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);

    cout << "Searching Data" << endl;
    cout << "Enter the data that u want to search: ";
    int searchData;
    cin >> searchData;

    // bool result = search(root, searchData); // Space Complexity - O(h) Recursive Search
    bool result = searchIteratively(root, searchData); // Space Complexity - O(1) Iterative Search

    if (result)
    {
        cout << "It is Present in the BST" << endl;
    }
    else
    {
        cout << "It is not present in the BST" << endl;
    }

    // int minimum = min(root);
    // int maximum = max(root);

    int minimum = min(root)->data;
    int maximum = max(root)->data;

    cout << "Minimum in BST: " << minimum << endl;
    cout << "Maximum in BST: " << maximum << endl;

    int nodeDelete;
    cout << "Enter the Node that u want to delete : ";
    cin >> nodeDelete;
    deleteFromBST(root, nodeDelete);
    levelOrderTraversal(root);
}