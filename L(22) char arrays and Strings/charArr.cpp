#include <iostream>
#include <array>
using namespace std;

int lengthOfArray(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main()
{
    char name[20];
    // char name[20] = "Arghadip\0Biswas";
    cout << "Enter your name : ";
    cin >> name;
    cout << "Your name is " << name << endl;
    cout << "Length of the array : " << lengthOfArray(name);

    return 0;
}
