#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>
using namespace std;

typedef long long ll;

int main()
{
    string s;
    stack<ll> st;
    ll temp = 0, ans;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '.')
        {
            st.push(temp);
            temp = 0;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            temp *= 10;
            temp += s[i] - '0';
        }
        else if (s[i] == '+')
        {
            int x, y;
            x = st.top();
            st.pop();
            y = st.top();
            st.pop();
            st.push(x + y);
        }
        else if (s[i] == '-')
        {
            int x, y;
            x = st.top();
            st.pop();
            y = st.top();
            st.pop();
            st.push(y - x);
        }
        else if (s[i] == '*')
        {
            int x, y;
            x = st.top();
            st.pop();
            y = st.top();
            st.pop();
            st.push(x * y);
        }
        else if (s[i] == '/')
        {
            int x, y;
            x = st.top();
            st.pop();
            y = st.top();
            st.pop();
            st.push(y / x);
        }
        else if (s[i] == '@')
        {
            ans = st.top();
            cout << ans << endl;
            system("pause");
            return 0;
        }
        else
        {
            cout << "Warning!";
            system("pause");
            return 0;
        }
    }
}