#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1005;

ll a[N], sum[N], ans = 0;
int n, c;

void dfs(int id, ll cur)
{
    if (sum[id - 1] + cur <= c)
    {
        ans = max(ans, sum[id - 1] + cur);
        return;
    }
    if (cur > c)
        return;
    ans = max(ans, cur);
    for (int i = 1; i < id; i++)
        dfs(i, cur + a[i]);
    return;
}

int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    dfs(n + 1, 0);
    cout << ans << endl;
    system("pause");
}