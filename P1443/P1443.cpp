#include <bits/stdc++.h>
using namespace std;

int d[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

queue<pair<int, int>> q;

int vis[500][500];
int f[500][500];

int main()
{
    memset(vis, 0, sizeof(vis));
    memset(f, -1, sizeof(f));
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    f[X][Y] = 0;
    vis[X][Y] = 1;
    q.push(make_pair(X, Y));
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int dx = x + d[i][0];
            int dy = y + d[i][1];
            if (vis[dx][dy] || dx < 1 || dy < 1 || dx > n || dy > m)
                continue;
            f[dx][dy] = f[x][y] + 1;
            vis[dx][dy] = 1;
            q.push(make_pair(dx, dy));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << f[i][j] << ' ';
        cout << endl;
    }
    system("pause");
    return 0;
}