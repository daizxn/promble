#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
int main(){
    int n,id;
    string x,maxx="";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        ull x_size=x.size();
        ull maxx_size=maxx.size();
        if(x_size>maxx_size||(x_size==maxx_size&&x>maxx)){
            maxx=x;
            id=i;
        }
    }
    cout<<id<<endl<<maxx<<endl;
    system("pause");
    return 0;
}