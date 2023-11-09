#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

const int N = 1e5 + 5;

struct node
{
    int s, a;
};

int sum[N], front[N], behind[N];
node v[N];

bool cmp(node x, node y)
{
    return x.a > y.a;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> v[i].s;
    for (int i = 1; i <= n; i++)
        std::cin >> v[i].a;
    std::sort(v + 1, v + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + v[i].a;
    for (int i = 1; i <= n; i++)
        front[i] = std::max(front[i - 1], 2 * v[i].s);
    for (int i = n; i >= 1; i--)
        behind[i] = std::max(behind[i + 1], 2 * v[i].s + v[i].a);
    for (int i = 1; i <= n; i++)
        std::cout << std::max(sum[i] + front[i], sum[i - 1] + behind[i]) << std::endl;
    system("pause");
    return 0;
}