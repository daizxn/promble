#include <iostream>
#include <algorithm>
using namespace std;

int num[400], cnt[5], dp[45][45][45][45];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    dp[0][0][0][0] = num[1];
    for (int i = 0; i <= cnt[1]; i++)
        for (int j = 0; j <= cnt[2]; j++)
            for (int k = 0; k <= cnt[3]; k++)
                for (int p = 0; p <= cnt[4]; p++)
                {
                    int t = 1 + i + j * 2 + k * 3 + p * 4;
                    if (i)
                        dp[i][j][k][p] = max(dp[i - 1][j][k][p] + num[t], dp[i][j][k][p]);
                    if (j)
                        dp[i][j][k][p] = max(dp[i][j - 1][k][p] + num[t], dp[i][j][k][p]);
                    if (k)
                        dp[i][j][k][p] = max(dp[i][j][k - 1][p] + num[t], dp[i][j][k][p]);
                    if (p)
                        dp[i][j][k][p] = max(dp[i][j][k][p - 1] + num[t], dp[i][j][k][p]);
                }
    cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl;
    return 0;
}