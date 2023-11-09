#include <iostream>
#include <bits/std_abs.h>
using namespace std;

const int N = 3e4 + 5;

int f[N], sum[N], size[N];

void inti()
{
    for (int i = 1; i <= 30001; i++)
    {
        f[i] = i;
        sum[i] = 0;
        size[i] = 1;
    }
}
int find(int x)
{
    if (f[x] != x)
    {
        int fn = find(f[x]);
        sum[x] += sum[f[x]];
        return f[x] = fn;
    }

    return f[x];
}

int main()
{
    std::ios::sync_with_stdio(false);
    inti();
    int T;
    cin >> T;
    while (T--)
    {
        char op;
        int x, y;
        cin >> op >> x >> y;
        switch (op)
        {
        case 'M':
        {
            int fx = find(x);
            int fy = find(y);

            f[fx] = fy;
            sum[fx] += size[fy];
            size[fy] += size[fx];
            size[fx] = 0;

            break;
        }
        case 'C':
        {
            int fx = find(x);
            int fy = find(y);
            if (fx == fy)
                cout << (abs(sum[x] - sum[y]) - 1) << endl;
            else
                cout << -1 << endl;
            break;
        }
        }
    }
    system("pause");
    return 0;
}