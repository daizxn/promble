#include <iostream>
#include <stdlib.h>

using namespace std;

const int N = 5e4 + 5;
const int K = 1e5 + 5;

int f[3 * N];

int find(int x)
{
    if (f[x] != x)
        return f[x] = find(f[x]);
    return f[x];
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= 3 * n; i++)
        f[i] = i;
    for (int i = 1; i <= k; i++)
    {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (x > n || y > n)
        {
            ans++;
            continue;
        }
        if (opt == 1)
        {
            if (find(x + n) == find(y) || find(x + 2 * n) == find(y))
            {
                ans++;
                continue;
            }
            else
            {
                f[find(x)] = find(y);
                f[find(x + n)] = find(y + n);
                f[find(x + 2 * n)] = find(y + 2 * n);
            }
        }
        else
        {
            if (find(x) == find(y) || find(x) == find(y + n))
            {
                ans++;
                continue;
            }
            else
            {
                f[find(x + n)] = find(y);
                f[find(x + 2 * n)] = find(y + n);
                f[find(x)] = find(y + 2 * n);
            }
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}