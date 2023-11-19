#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int dp[25005], a[105];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(dp, 0, sizeof dp);
        memset(a, 0, sizeof a);
        int n;
        dp[0] = 1;
        cin >> n;
        int ans = n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (dp[a[i]])
            {
                ans--;
                continue;
            }
            for (int j = a[i]; j <= a[n]; j++)
                dp[j] = dp[j] | dp[j - a[i]];
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}