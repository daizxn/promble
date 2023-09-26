#include <bits/stdc++.h>
using namespace std;

int n, len = 0, ans = -1;
int ch[25][25], vis[25];
string str[25];
char kt;

int meet(int a, int b)
{
    for (int i = str[a].size() - 1; i >= 0; i--)
    {
        int k = 0;
        bool flag = 0;
        for (int j = i; j < str[a].size(); j++)
            if (str[a][j] != str[b][k++])
            {
                flag = 1;
                break;
            }
        if (!flag)
            return str[a].size() - i;
    }
    return 0;
}
void dfs(int a)
{
    bool flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] >= 2)
            continue;
        if (!ch[a][i])
            continue;
        if (ch[a][i] == str[a].size() || ch[a][i] == str[i].size())
            continue;
        flag = 1;
        len += str[i].size() - ch[a][i];
        vis[i]++;
        dfs(i);
        vis[i]--;
        len -= str[i].size() - ch[a][i];
    }
    if (!flag)
        ans = max(ans, len);
    return;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> str[i];
    cin >> kt;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ch[i][j] = meet(i, j);
    for (int i = 1; i <= n; i++)
    {
        if (str[i][0] == kt)
        {
            vis[i]++;
            len = str[i].size();
            dfs(i);
            vis[i]--;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}