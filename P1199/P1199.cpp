#include <iostream>
#include <algorithm>
#include <stdlib.h>

const int N = 505;

int a[N][N];

int main()
{
    int n, ans = 0;
    std::cin >> n;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            std::cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    for (int i = 1; i <= n; i++)
    {
        std::sort(a[i] + 1, a[i] + n + 1);
        ans = ans > a[i][n - 1] ? ans : a[i][n - 1];
    }
    std::cout<<1<<'\n'<<ans<<'\n';
    system("pause");
    return 0;
}