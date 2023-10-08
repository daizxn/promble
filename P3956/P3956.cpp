#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int inf = 0x7fffffff;

struct node
{
    int x, y, c, v;
};

queue<node> q;

int a[N][N], val[N][N];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, ans = inf;

int read();
void inti();
void mbfs();

int main()
{
    m = read();
    n = read();
    inti();
    for (int x, y, c, i = 1; i <= n; i++)
    {
        x = read();
        y = read();
        c = read();
        a[x][y] = c;
    }
    mbfs();
    if (ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;
    // system("pause");
    return 0;
}

int read()
{
    int x = 0, f = 1;
    char ch;
    ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return f * x;
}
void inti()
{
    for (int i = 0; i <= m + 5; i++)
        for (int j = 0; j <= m + 5; j++)
        {
            a[i][j] = -1;
            val[i][j] = inf;
        }
    return;
}
void mbfs()
{
    q.push((node){1, 1, a[1][1], 0});
    val[1][1] = 0;
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, c = q.front().c, v = q.front().v;
        q.pop();
        if (v > ans)
            continue;
        if (x == m && y == m)
            ans = min(ans, v);
        for (int i = 0; i < 4; i++)
        {
            int dx = x + d[i][0], dy = y + d[i][1];
            if (dx < 1 || dx > m || dy < 1 || dy > m)
                continue;
            int lc = a[x][y], dc = a[dx][dy], nv = val[dx][dy], dv;
            if (lc >= 0 && dc >= 0)
            {
                if (lc == dc)
                    dv = v;
                else
                    dv = v + 1;
                if (dv < nv)
                {
                    q.push((node){dx, dy, dc, dv});
                    val[dx][dy] = dv;
                }
            }
            else if (lc >= 0 && dc < 0)
            {
                dv = v + 2;
                if (dv < nv)
                {
                    q.push((node){dx, dy, lc, dv});
                    val[dx][dy] = dv;
                }
            }
            else if (lc < 0 && dc >= 0)
            {
                if (c == dc)
                    dv = v;
                else
                    dv = v + 1;
                if (dv < nv)
                {
                    q.push((node){dx, dy, dc, dv});
                    val[dx][dy] = dv;
                }
            }
        }
    }
    return;
}