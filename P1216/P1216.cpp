#include <iostream>

using namespace std;

const int N = 1e3 + 5;

int a[N][N], dp[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= i; j++)
        {
            if (i == n)
                dp[i][j] = a[i][j];
            if (dp[i + 1][j] > dp[i + 1][j + 1])
                dp[i][j] = a[i][j] + dp[i + 1][j];
            else
                dp[i][j] = a[i][j] + dp[i + 1][j + 1];
        }

    cout << dp[1][1];
    return 0;
}