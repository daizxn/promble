#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int n;
    cin >> s >> n;
    int len = s.size();
    while (n)
    {
        int t = len-1;
        for (int i = 1; i < len; i++)
            if (s[i - 1] > s[i])
            {
                t = i - 1;
                break;
            }
        s.erase(t, 1);
        n--;
        len--;
    }
    while (s[0] == '0')
        s.erase(0, 1);
    if (s != "")
        cout << s << endl;
    else
        cout << 0 << endl;
    return 0;
}