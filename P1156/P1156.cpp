#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1005;
const int inf = 0x3f3f3f3f;

struct node
{
    int t, h, v;
    bool operator<(const node &x)
    {
        return t < x.t;
    }
};

node a[N];
int dp[N][N];

int main()
{
    int n, m;
    int ans = -inf;
    memset(dp, ~0x3f, sizeof dp);
    dp[0][0] = 10;
    a[0].t = 0;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].t >> a[i].v >> a[i].h;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            if (dp[i - 1][j] < a[i].t - a[i - 1].t)
                continue;
            if (j + a[i].h >= m)
            {
                cout << a[i].t << endl;
                return 0;
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i].v - (a[i].t - a[i - 1].t));
            dp[i][j + a[i].h] = max(dp[i][j + a[i].h], dp[i - 1][j] - (a[i].t - a[i - 1].t));
        }
        ans = max(dp[i][0] + a[i].t, ans);
    }
    cout << ans << endl;
    return 0;
}
/*
dp[i][j]表示第i个垃圾到高度j是的血量
for 垃圾i:
    for 高度j:
        if(dp[i][j]-(a[i].t-a[i-1].t)<0)continue//死了
        if(j+a[i].h>m)return 0//出来了
        吃
        dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i].v-(a[i].t-a[i-1].t))
        不吃
        dp[i][j]=max(dp[i][j],dp[i-1][j-a[i].h]-(a[i].t-a[i-1].t))
*/