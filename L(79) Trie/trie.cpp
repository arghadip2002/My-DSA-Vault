#include <iostream>
using namespace std;

class Trienode
{
public:
    char data;
    Trienode *children[26];
    bool isTerminal;

    Trienode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    Trienode *root;

    Trie()
    {
        root = new Trienode('\0'); // ✅ Initialize root
    }

    void insertUtil(Trienode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A'; // Assumes uppercase letters
        Trienode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new Trienode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    bool searchUtil(Trienode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        Trienode *child = root->children[index];

        if (child == nullptr)
        {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("APPLE");
    t->insertWord("APP");
    cout << "Words inserted successfully!" << endl;

    string word = "APPLEANDMANGO";

    if (t->searchWord(word))
    {
        cout << "PRESENT" << endl;
    }
    else
    {
        cout << "ABSENT" << endl;
    }
    return 0;
}
