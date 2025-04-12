#include <iostream>
using namespace std;

int main()
{
    int i = 1, sum = 0, n;

    cin >> n;

    while (i <= n)
    {
        sum = sum + i;
        i = i + 1;
    }
    cout << "The sum of the number is " << sum << endl;
}
