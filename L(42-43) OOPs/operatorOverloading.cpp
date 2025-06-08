#include <iostream>
using namespace std;

class B
{
public:
    int a;
    int b;

    int add()
    {
        return a + b;
    }

    // operator overloading
    void operator+(B &obj)
    {
        int value1 = this->a; // obj1.a
        int value2 = obj.a;   // Obj2.a
        cout << value2 - value1 << endl;
    }
};

int main()
{
    B obj1, obj2;
    obj1.a = 1;
    obj2.a = 2;

    obj1 + obj2; // Here First one (Obj1) is the calling function, and the second one (Obj2) is the passed function
}