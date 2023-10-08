#include <bits/stdc++.h>
using namespace std;

const int N = 45;

int a[N][N], b[N][N], n;
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void dfs(int x, int y)
{
    if (x < 0 || x > n + 1 || y < 0 || y > n + 1 || a[x][y])
        return;
    a[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int dx = x + d[i][0];
        int dy = y + d[i][1];
        dfs(dx, dy);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    dfs(0, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!a[i][j])
                cout << "2 ";
            else
                cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
}