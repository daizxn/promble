#include <iostream>
#include <algorithm>

const int N = 2e5 + 5;

struct person
{
    int id, s, w;
    bool operator<(const person &x)
    {
        if (s != x.s)
            return s > x.s;
        return id < x.id;
    }
};

person p[N], lose[N], win[N];

int main()
{
    int n, r, q;
    std::cin >> n >> r >> q;
    for (int i = 1; i <= 2 * n; i++)
        std::cin >> p[i].s;
    for (int i = 1; i <= 2 * n; i++)
        std::cin >> p[i].w;
    for (int i = 1; i <= 2 * n; i++)
        p[i].id = i;
    std::sort(p + 1, p + 2 * n + 1);
    while (r--)
    {
        for (int i = 1; i <= n; i++)
        {
            if (p[2 * i - 1].w >= p[2 * i].w)
            {
                p[2 * i - 1].s++;
                win[i] = p[2 * i - 1];
                lose[i] = p[2 * i];
            }
            else
            {
                p[2 * i].s++;
                win[i] = p[2 * i];
                lose[i] = p[2 * i - 1];
            }
        }
        std::merge(win + 1, win + 1 + n, lose + 1, lose + 1 + n, p + 1);
    }
    std::cout << p[q].id;
    system("pause");
    return 0;
}