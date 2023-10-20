#include <iostream>
#include <stdlib.h>
#include<string.h>
using namespace std;

const int N = 4e5 + 5;

struct node
{
    int from, next, to;
};

int head[N], ans[N], f[N], broken[N];
bool BK[N];
int tot = 0;
node e[N];

void add(int u, int v)
{
    e[++tot].from = u;
    e[tot].next = head[u];
    head[u] = tot;
    e[tot].to = v;
}
int find(int x)
{
    if (f[x] != x)
        return f[x] = find(f[x]);
    return f[x];
}

int main()
{
    std::ios::sync_with_stdio(false);
    memset(BK,0,sizeof BK);

    int n, m, k, totle;
    cin >> n >> m;
    for (int i = 0; i <= n; i++){
        f[i] = i;
        head[i]=-1;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
        
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> broken[i];
        BK[broken[i]] = 1;
    }
    totle = n - k;
    for (int i = 1; i <= 2 * m; i++)
        if (!BK[e[i].from] && !BK[e[i].to] && find(e[i].from) != find(e[i].to))
        {
            totle--;
            f[find(e[i].from)] = find(e[i].to);
        }
    ans[k + 1] = totle;
    for (int i = k; i >= 1; i--)
    {
        BK[broken[i]] = 0;
        totle++;
        for (int j = head[broken[i]]; j!=-1; j = e[j].next)
        {
            if (!BK[e[j].to] && find(broken[i]) != find(e[j].to))
            {
                totle--;
                f[find(broken[i])] = find(e[j].to);
            }
        }
        ans[i] = totle;
    }
    for (int i = 1; i <= k + 1; i++)
        cout << ans[i] << endl;
    system("pause");
    return 0;
}