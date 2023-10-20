#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

bool is_prime(int x)
{
    if (x == 1)
        return false;
    if (x == 2)
        return true;
    for (int i = 2; i < x; i++)
    {
        if (x % i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int l;
    cin >> l;
    int x = 2;
    int count = 0;
    while(l>0)
    {
        if (is_prime(x))
        {
            cout << x << endl;
            l -= x;
            count++;
        }
        x++;
    }
    cout << count << endl;
    system("pause");
    return 0;
}

// i   sqrt(x)