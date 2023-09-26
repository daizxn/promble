#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 100;

int a[N];

int main()
{
    int n, w;
    cin >> w >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int i = 1, j = n, ans = 0;
    while (i <= j)
    {
        if (a[i] + a[j] <= w)
        {
            ans++;
            i++;
            j--;
        }
        else
        {
            ans++;
            j--;
        }
    }
    cout << ans << endl;
    // system("pause");
    return 0;
}