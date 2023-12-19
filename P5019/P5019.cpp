#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (a[i - 1] < a[i])
            sum += a[i] - a[i - 1];
    cout << sum << endl;
    return 0;
}