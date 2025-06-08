#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    float ans = 0;
    int i = 0;
    // while (n != 0)
    // {
    //     cout << "Step " << i << endl;
    //     int digit = n % 2;
    //     cout << digit << endl;

    //     n = n / 2;
    //     cout << n << endl;

    //     ans = (digit * pow(10, i)) + ans;
    //     cout << ans << endl;

    //     i++;
    // }
    // ---------------------------------------------------------------

    while (n != 0)
    {
        int bit = n & 1;
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }

    cout << "Answer --> " << ans << endl;

    return 0;
}