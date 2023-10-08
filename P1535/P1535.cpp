#include <iostream>
using namespace std;

const int N = 110;

int n, m, t, x1, x2, y1, y2, ans = 0;
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool e[N][N];

inline int abs(int x)
{
    if (x < 0)
        return -x;
    else
        return x;
}
inline void dfs(int x, int y, int time)
{
    if (x == x2 && y == y2 && !time)
        ans++;
    if (!time || abs(x2 - x) + abs(y2 - y) > time)
        return;
    for (int i = 0; i < 4; i++)
    {
        int dx = x + d[i][0];
        int dy = y + d[i][1];
        if (e[dx][dy] && dx >= 1 && dx <= n && dy >= 1 && dy <= m)
            dfs(dx, dy, time - 1);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                e[i][j] = 1;
            else
                e[i][j] = 0;
        }
    cin >> x1 >> y1 >> x2 >> y2;
    dfs(x1, y1, t);
    cout << ans << endl;
    system("pause");
    return 0;
}