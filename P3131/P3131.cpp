#include <bits/stdc++.h>
using namespace std;

int l[7] = {0, -1, -1, -1, -1, -1, -1}, r[7];
int S = 0;


int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        S = (S + a) % 7;
        if (l[S] == -1)
            l[S] = i;
        r[S] = i;
    }
    int ans = 0;
    for (int i = 0; i < 7; i++)
        if (l[i] != -1)
            ans = max(ans, r[i] - l[i]);
    cout << ans << endl;
    system("pause");
    return 0;
}
