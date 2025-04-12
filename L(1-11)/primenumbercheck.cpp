#include <iostream>
using namespace std;

int main()
{
    int i, n;

    cin >> n;

    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            break;
        }
    }

    if (i == n)
    {
        cout << "The number is prime";
    }
    else
    {
        cout << "The number is not prime";
    }
}
