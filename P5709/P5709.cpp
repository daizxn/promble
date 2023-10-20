#include <iostream>
#include<stdlib.h>
// #include<bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int m, t, s;
    cin >> m >> t >> s;
    if(t==0){
        cout<<0<<endl;
        return 0;
    }
    int temp;
    if (s % t)
        temp = s / t + 1;
    else
        temp = s / t;
    if(temp>m){
        cout<<0<<endl;
        return 0;
    }
    cout << m - temp << endl;
    system("pause");
    return 0;
}