#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;

long long d[N],s[N],t[N],r[N],diff[N],need[N],n,m;

int read();
bool check(int x);
int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++)
        r[i]=read();
    for(int i=1;i<=m;i++){
        d[i]=read();
        s[i]=read();
        t[i]=read();
    }
    if(check(m)){
        cout<<"0"<<endl;
        return 0;
    }
    int begin=0,end=m,mid,ans;
    while(begin<=end){
        mid=(begin+end)>>1;
        if(check(mid)){
            ans=mid;
            begin=mid+1;
        }
        else 
            end=mid-1;
    }
    cout<<"-1"<<endl<<ans+1<<endl;
    system("pause");
    return 0;
}

int read(){
    char ch;
    int x=0,f=1;
    ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

bool check(int x){
    memset(diff,0,sizeof diff);
    for(int i=1;i<=x;i++){
        diff[s[i]]+=d[i];
        diff[t[i]+1]-=d[i];
    }
    for(int i=1;i<=n;i++){
        need[i]=need[i-1]+diff[i];
        if(need[i]>r[i])
            return 0;
    }
    return 1;
}