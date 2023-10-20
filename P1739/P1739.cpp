#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
    string s;
    int ok = 0;
    cin >> s;
    int len = s.length();
    if (s[0] == ')')
    {
        cout << "NO" << endl;
        system("pause");
        return 0;
    }
    for (int i = 0; i < len - 1; i++)
    {
        if (ok < 0)
            break;
        if (s[i] == '(')
            ok++;
        else if (s[i] == ')')
            ok--;
        else
            continue;
    }
    if (!ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    system("pause");
    return 0;
}