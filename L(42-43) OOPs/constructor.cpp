#include <iostream>
using namespace std;

class Hero
{

    // Properties
private:
    int health;

public:
    char level;

    // Default Constructor
    Hero()
    {
        cout << "Default Constructor is called" << endl;
    }

    // Parameterised Constructor
    Hero(int health)
    {
        this->health = health;
        cout << "First Parameterised Constructor is called." << endl;
        cout << "this -> " << this << endl;
    }

    Hero(int health, int level)
    {
        this->health = health;
        this->level = level;
        cout << "Second Parameterised Constructor is called." << endl;
        cout << "this -> " << this << endl;
    }

    void print()
    {
        cout << "Health - " << health << endl;
        cout << "level - " << level << endl;
    }
};

int main()
{
    // static allocation
    Hero h1(10);
    cout << "adress of h1 - " << &h1 << endl;
    h1.level = 'A';
    h1.print();

    Hero h2(100, 'B');
    cout << "adress of h1 - " << &h1 << endl;
    h2.print();

    // Hero h1;

    // Dynamic memory allocation
    Hero *h3 = new Hero;
}