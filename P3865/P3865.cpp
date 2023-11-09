#include <iostream>
#include <cmath>
#include <algorithm>

const int N = 1e5 + 5;

int lg[N], f[N][40];

inline int read()
{
    int x = 0, f = 1;
    char ch = std::getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = std::getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = std::getchar();
    }
    return x * f;
}

int main()
{
    int n, m;
    n = read();
    m = read();
    lg[0] = -1;
    for (int i = 1; i <= n; i++)
        lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= n; i++)
        f[i][0] = read();
    for (int j = 1; j <= lg[n]; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            f[i][j] = std::max(f[i][j - 1], f[i + (1 << j) + 1][j - 1]);
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        l = read();
        r = read();
        int t = lg[r - l + 1];
        std::cout << std::max(f[l][t], f[r - (1 << t) + 1][t]) << std::endl;
    }
    system("pause");
    return 0;
}