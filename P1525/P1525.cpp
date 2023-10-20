#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e4 + 5;
const int M = 1e5 + 5;

struct node
{
    int x, y, z;
};

node a[M];
int f[N], enemy[N];

bool cmp(node x, node y)
{
    return x.z > y.z;
}
int find(int x)
{
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].x >> a[i].y >> a[i].z;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m + 1; i++)
    {
        int fx = find(a[i].x), fy = find(a[i].y);
        if (fx == fy)
        {
            cout << a[i].z << endl;
            system("pause");
            return 0;
        }
        else
        {
            if (!enemy[a[i].x])
                enemy[a[i].x] = a[i].y;
            else
                f[find(enemy[a[i].x])] = fy;
            if (!enemy[a[i].y])
                enemy[a[i].y] = a[i].x;
            else
                f[find(enemy[a[i].y])] = fx;
        }
    }
    cout << 0 << endl;
    system("pause");
    return 0;
}