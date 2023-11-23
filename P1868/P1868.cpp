#include <iostream>
#include <vector>

using namespace std;

const int N = 3e6 + 5;

vector<int> v[N];
int dp[N];

int main()
{
    int n, maxi;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[y].push_back(x - 1);
        maxi = max(maxi, y);
    }
    dp[0] = 0;
    for (int i = 1; i <= maxi; i++)
    {
        dp[i] = dp[i - 1];
        for (int j = 0; j < v[i].size(); j++)
        {
            dp[i] = max(dp[i], dp[v[i][j]] + i - v[i][j]);
        }
    }
    cout << dp[maxi] << endl;
    return 0;
}