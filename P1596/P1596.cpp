#include <iostream>

using namespace std;

int d[8][2] = {{1, 0}, {-1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, -1}};
char c[105][105];
int n, m;

void dfs(int x, int y)
{
    c[x][y] = '.';
    for (int i = 0; i < 8; i++)
    {
        int dx = x + d[i][0];
        int dy = y + d[i][1];
        if (dx >= 0 && dx <= n && dy >= 0 && dy <= m && c[dx][dy] == 'W')
            dfs(dx, dy);
    }
    return;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (c[i][j] == 'W')
            {
                dfs(i, j);
                ans++;
            }
    cout << ans << endl;
    return 0;
}