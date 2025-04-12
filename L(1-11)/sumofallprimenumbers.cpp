#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 0 || n == 1)
        cout << "The Sum of even numbers is 0";

    else if (n < 0)
        cout << "Invalid Input";

    else if (n == 2)
        cout << "The Sum of even numbers is 2";

    else
    {
        int i, j, sum = 2;
        for (i = 3; i <= n; i++)
        {
            for (j = 2; j < i; j++)
            {
                if (i % j == 0)
                    break;
            }

            if (j == i)
                sum = sum + i;
        }
        cout << "The Sum of even numbers is " << sum << endl;
    }
}
