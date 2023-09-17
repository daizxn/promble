#include<bits/stdc++.h>
using namespace std;

struct milk{
    int p,l;
    bool operator<(const milk &x){
        return p<x.p;
    }
};
milk a[5005];

int main(){
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i].p>>a[i].l;
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++){
        if(n>=a[i].l){
            sum+=a[i].l*a[i].p;
            n-=a[i].l;
        }
        else{
            sum+=n*a[i].p;
            n=0;
        }
    }
    cout<<sum<<endl;
    system("pause");
    return 0;
}