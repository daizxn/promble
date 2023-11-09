#include <iostream>
#include <algorithm>

const int N = 1e5 + 5;

int st[N][32];
int lg[N];
int n, m;

inline int read();
inline void init();
inline void st_build();

int main()
{
    init();
    n = read();
    m = read();
    for (int i = 1; i <= n; i++)
        st[i][0] = read();
    st_build();
    for (int i = 1; i <= n - m + 1; i++)
        std::cout << std::min(st[i][lg[m]], st[i + m - (1 << lg[m])][lg[m]]) << '\n';
    system("pause");
    return 0;
}

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
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
    return x * f;
}

inline void init()
{
    lg[0] = -1;
    for (int i = 1; i <= N; i++)
        lg[i] = lg[i >> 1] + 1;
    return;
}

inline void st_build()
{
    for (int j = 1; j <= lg[n]; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            st[i][j] = std::min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    return;
}