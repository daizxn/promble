#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e3 + 5;
const int M = 1e5 + 5;

struct node
{
    int x, y, t;
} a[M];

int f[N];

bool cmp(node x, node y)
{
    return x.t < y.t;
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
        cin >> a[i].x >> a[i].y >> a[i].t;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        int fx = find(a[i].x), fy = find(a[i].y);
        if (fx != fy)
        {
            f[fx] = fy;
            n--;
        }
        if (n == 1)
        {
            cout << a[i].t << endl;
            system("pause");
            return 0;
        }
    }
 //   cout << "ERR" << endl;
    return 0;
}