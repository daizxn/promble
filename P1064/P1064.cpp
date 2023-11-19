#include <iostream>
#include <algorithm>

using namespace std;

const int N = 32005;
const int M = 65;

int dp[N], mw[M], mv[M], fn[M][5], fv[M][5];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int v, p, q;
        cin >> v >> p >> q;
        if (!q)
        {
            mw[i] = v;
            mv[i] = v * p;
            continue;
        }
        fn[q][0]++;
        fn[q][fn[q][0]] = v;
        fv[q][fn[q][0]] = v * p;
    }
    for (int i = 1; i <= m; i++)
        for (int j = n; j >= mw[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - mw[i]] + mv[i]);
            if (j >= mw[i] + fn[i][1])
                dp[j] = max(dp[j], dp[j - mw[i] - fn[i][1]] + mv[i] + fv[i][1]);
            if (j >= mw[i] + fn[i][2])
                dp[j] = max(dp[j], dp[j - mw[i] - fn[i][2]] + mv[i] + fv[i][2]);
            if (j >= mw[i] + fn[i][1] + fn[i][2])
                dp[j] = max(dp[j], dp[j - mw[i] - fn[i][1] - fn[i][2]] + mv[i] + fv[i][1] + fv[i][2]);
        }
    cout << dp[n] << endl;
    system("pauxe");
    return 0;
}