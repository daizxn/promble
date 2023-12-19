#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e4 + 5;

int l[N], r[N], len[N], dp[N][2];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        len[i] = r[i] - l[i];
    }
    dp[1][0] = r[1] - 1 + len[1];
    dp[1][1] = r[1] - 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][0] + abs(r[i] - l[i - 1]), dp[i - 1][1] + abs(r[i - 1] - r[i])) + len[i] + 1;
        dp[i][1] = min(dp[i - 1][0] + abs(l[i - 1] - l[i]), dp[i - 1][1] + abs(r[i - 1] - l[i])) + len[i] + 1;
    }
    int ans = min(dp[n][0] + n - l[n], dp[n][1] + n - r[n]);
    cout << ans << endl;
    return 0;
}