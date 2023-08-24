#include<bits/stdc++.h>
using namespace std;

const int N=200005;
struct person{
    int s,id,w;
    bool operator<(const person &x){
        if(x.s!=s)return s>x.s;
        return id<x.id;
    }
};

person p[N],win[N],lose[N];

int main(){
    int n,r,q;
    cin>>n>>r>>q;
    for(int i=1;i<=n*2;i++)cin>>p[i].s;
    for(int i=1;i<=n*2;i++)cin>>p[i].w;
    for(int i=1;i<=n*2;i++)p[i].id=i;
    sort(p+1,p+n*2+1);
    while(r--){
        for(int i=1;i<=n;i++){
            #define l i*2-1
            #define r i*2
            if(p[l].w<p[r].w){
                p[r].s++;
                lose[i]=p[l];
                win[i]=p[r];
            }
            else{
                p[l].s++;
                lose[i]=p[r];
                win[i]=p[l];
            }
        }
        merge(lose+1,lose+n+1,win+1,win+1+n,p+1);
    }
    cout<<p[q].id<<endl;
    system("pause");
    return 0;
}