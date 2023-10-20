#include <iostream>
#include <stack>
using namespace std;

stack<int> x;

int main()
{
    int a, b;
    char c;
    cin >> a;
    int m = 10000;
    a = a % m;
    x.push(a);
    while (cin >> c >> b)
    {
        if (c == '*')
        {
            a = x.top();
            x.pop();
            x.push(a * b % m);
        }
        else
            x.push(b);
    }
    a = 0;
    while (!x.empty())
    {
        a += x.top();
        a %= m;
        x.pop();
    }
    cout << a << endl;
    system("pause");
    return 0;
}
