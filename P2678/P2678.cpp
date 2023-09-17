#include<bits/stdc++.h>
using namespace std;

const int N=50005;

int d,n,m;
int a[N];

int read();
bool check(int x);

int main(){
    d=read();n=read();m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    a[n+1]=d;
    int l=1,r=d,ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<ans<<endl;
    // system("pause");
    return 0;
}

inline int read(){
    char ch=getchar();
    int x=0,f=1;
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
    int cnt=0;
    int i=0;
    int now=0;
    while(i<=n){
        i++;
        if(a[i]-a[now]<x)
            cnt++;
        else
            now=i;
    }
    return (cnt>m)?0:1;
}