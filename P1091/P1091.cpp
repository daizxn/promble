#include <iostream>
#include <algorithm>
using namespace std;

int a[105], dp1[105], dp2[105];

int main()
{
    int n, ans = 0x7fffffff;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp1[i] = dp2[i] = 1;
    }
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[i] > a[j] && dp1[i] < dp1[j] + 1)
                dp1[i] = dp1[j] + 1;
    for (int i = n - 1; i >= 1; i--)
        for (int j = n; j > i; j--)
            if (a[i] > a[j] && dp2[i] < dp2[j] + 1)
                dp2[i] = dp2[j] + 1;
    for (int i = 1; i <= n; i++)
        ans = min(ans, n - dp1[i] - dp2[i] + 1);
    cout << ans;
    return 0;
}