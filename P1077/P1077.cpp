#include <iostream>
#include <algorithm>

using namespace std;

const int N = 105;
const int mod = 1e6 + 7;

int a[N], dp[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= m; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = j; k >=j-a[i]; k--)
                if(k>=0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
    cout << dp[n][m] << endl;
    return 0;
}

// dp[i][j]表示用i种花摆j盆的总数
// dp[i][j]+=dp[i-1][j-x]