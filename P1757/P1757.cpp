#include <iostream>
#include <algorithm>
using namespace std;

int g[205][205];
int w[10001], z[10001];
int b[10001];
int dp[10001];

int main()
{
    int n, m;
    int t;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> w[i] >> z[i] >> x;
        t = max(t, x);
        b[x]++;
        g[x][b[x]] = i;
    }
    for (int i = 1; i <= t; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 1; k <= b[i]; k++)
                if (j >= w[g[i][k]])
                    dp[j] = max(dp[j], dp[j - w[g[i][k]]] + z[g[i][k]]);

    cout << dp[m] << endl;
    return 0;
}