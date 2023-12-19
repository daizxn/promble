#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e4 + 5;

struct apple
{
    int h, s;
    bool operator<(const apple &x)
    {
        return s < x.s;
    }
} app[N];

int main()
{
    int n, s, a, b;
    int cnt = 0;
    cin >> n >> s >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x <= a + b)
        {
            cnt++;
            app[cnt].h = x;
            app[cnt].s = y;
        }
    }
    sort(app + 1, app + 1 + cnt);
    int res = s;
    int ans = 0;
    int t = 0;
    while (res > 0)
    {
        if (res >= app[++t].s)
        {
            res -= app[t].s;
            ans += 1;
        }
        if (t >= cnt)
            break;
    }
    cout << ans << endl;
}