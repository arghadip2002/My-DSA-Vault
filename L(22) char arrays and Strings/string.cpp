#include <iostream>
#include <array>
using namespace std;

int main()
{
    string name = "Arghadip";

    cout << "Your name is " << name << endl;
    cout << "Length of the array : " << name.length() << endl;
    name.push_back(' ');
    name.push_back('B');
    cout << "Your name after adding push_back is " << name << endl;

    name.pop_back();
    cout << "Your name after adding pop_back is " << name << endl;

    return 0;
}
