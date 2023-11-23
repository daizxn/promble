// dp[i][j][k][] a匹配到第i为，b匹配到第j为，到第k个子串 1为使用 0 为不使用
/*if a[i]==b[j]:
    选：
        dp[i][j][k][1]=dp[i-1][j-1][k][1]+dp[i-1][j-1][k-1][0]+dp[i-1][j-1][k-1][1];
    不选：
        dp[i][j][k][0]=dp[i-1][j][k][0]+dp[i-1][j][k][1];
else
    选：
        dp[i][j][k][1]=0;
    不选：
        dp[i][j][k][0]=dp[i-1][j][k][1]+dp[i-1][j][k][1];
*/
#include <iostream>

using namespace std;

const int mod = 1000000007;

char a[1005], b[205];
long long dp[2][205][205][2];

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int j = 1; j <= M; j++)
        cin >> b[j];
    dp[0][0][0][0] = dp[1][0][0][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        int cur = i & 1, pre = cur ^ 1;
        for (int j = 1; j <= M; j++)
        {
            for (int k = 1; k <= K; k++)
            {
                if (a[i] == b[j])
                {
                    dp[cur][j][k][0] = (dp[pre][j][k][0] + dp[pre][j][k][1]) % mod;
                    dp[cur][j][k][1] = (dp[pre][j - 1][k - 1][0] + dp[pre][j - 1][k - 1][1] + dp[pre][j - 1][k][1]) % mod;
                }
                else
                {
                    dp[cur][j][k][0] = (dp[pre][j][k][0] + dp[pre][j][k][1]) % mod;
                    dp[cur][j][k][1] = 0;
                }
            }
        }
    }
    cout << (dp[N & 1][M][K][0] + dp[N & 1][M][K][1]) % mod << endl;
    return 0;
}