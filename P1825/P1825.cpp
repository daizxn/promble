#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct point
{
    int x;
    int y;
    int t;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool v[305][305];
char c[305][305];
int n, m;
string s[305];

void portal(int &x, int &y);
int bfs(int x, int y);

int main()
{
    int x, y;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '@')
                x = i, y = j;
    int ans = bfs(x, y);
    cout << ans << endl;
}

int bfs(int x, int y)
{
    queue<point> q;
    q.push((point){x, y, 0});
    while (!q.empty())
    {
        point t = q.front();
        q.pop();
        if (s[t.x][t.y] == '=')
            return t.t;
        if (s[t.x][t.y] >= 'A' && s[t.x][t.y] <= 'Z')
            portal(t.x, t.y);
        for (int i = 0; i < 4; i++)
        {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            int nt = t.t + 1;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || v[nx][ny] || s[nx][ny] == '#')
                continue;
            q.push((point){nx, ny, nt});
            v[nx][ny] = 1;
        }
    }
}
void portal(int &x, int &y)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == s[x][y] && (i != x || j != y))
            {
                x = i;
                y = j;
                return;
            }
}