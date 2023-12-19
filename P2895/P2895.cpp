#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct point
{
    int x, y, t;
};

int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int a[305][305], vis[305][305];
queue<point> q;

int main()
{
    for (int i = 0; i <= 302; i++)
        for (int j = 0; j <= 302; j++)
            a[i][j] = -1;
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        if (t < a[x][y] || a[x][y] == -1)
            a[x][y] = t;
        for (int j = 0; j < 4; j++)
        {
            int dx = x + d[j][0];
            int dy = y + d[j][1];
            if (dx >= 0 && dy >= 0 && (t < a[dx][dy] || a[dx][dy] == -1))
                a[dx][dy] = t;
        }
    }
    point p;
    p.x = 0, p.y = 0, p.t = 0;
    vis[0][0] = 1;
    q.push(p);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (a[p.x][p.y] == -1)
        {
            cout << p.t << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int dx = p.x + d[i][0];
            int dy = p.y + d[i][1];
            int dt = p.t + 1;
            if (dx >= 0 && dy >= 0 & !vis[dx][dy] && (dt < a[dx][dy] || a[dx][dy] == -1))
            {
                q.push((point){dx, dy, dt});
                vis[dx][dy] = 1;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
