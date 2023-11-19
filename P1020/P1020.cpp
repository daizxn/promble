#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int a[N], d1[N], d2[N];

int main()
{
    int n;
    while (cin >> a[++n]);
    n--;
    int len1, len2;
    d1[1] = a[1];
    d2[1] = a[1];
    len1 = 1;
    len2 = 1;
    for (int i = 2; i <= n; i++)
    {
        if (d1[len1] >= a[i])
            d1[++len1] = a[i];
        else
        {
            int *p = upper_bound(d1 + 1, d1 + len1 + 1, a[i], greater<int>());
            *p = a[i];
        }
        if (d2[len2] < a[i])
            d2[++len2] = a[i];
        else
        {
            int *p = lower_bound(d2 + 1, d2 + len2 + 1, a[i]);
            *p = a[i];
        }
    }
    cout << len1 << endl
         << len2 << endl;
}