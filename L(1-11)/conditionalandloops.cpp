#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a;
    cin >> b;

    cout << "Value of a is " << a << " and "
         << "Value of b is " << b << endl;

    if (a == b)
    {
        cout << "Same";
    }
    else if (a > b)
    {
        cout << "a is bigger than b";
    }
    else
    {
        cout << "a is less than b";
    }
}
