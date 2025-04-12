#include <iostream>
using namespace std;

int main()
{
    int i, j, n;

    cin >> n;

    if (n == 0 || n == 1)
        cout << "no numbers";
    else if (n < 0)
        cout << "invalid input";
    else if (n == 2)
    {
        cout << n;
    }
    else
    {
        cout << "2 ";

        for (i = 3; i <= n; i++)
        {
            for (j = 2; j < i; j++)
            {
                if (i % j == 0)
                    break;
            }

            if (j == i)
            {
                cout << i << " ";
            }
        }
    }
}