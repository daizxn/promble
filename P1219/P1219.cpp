#include<bits/stdc++.h>
using namespace std;

int n;
int ans=0;
int a[40],b[40],c[40],d[40];

inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

void dfs(int x){
    if(x==n+1){
        ans++;
        if(ans>3)
            return;
        for(int i=1;i<=n;i++)
            printf("%d ",a[i]);
            puts("");
        return;
    }
    for(int i=1;i<=n;i++){
        if(b[i])continue;
        if(c[i-x+n])continue;
        if(d[i+x])continue;
        a[x]=i;
        b[i]=1;
        c[i-x+n]=1;
        d[i+x]=1;
        dfs(x+1);
        a[x]=0;
        b[i]=0;
        c[i-x+n]=0;
        d[i+x]=0;
    }
    return;
}

int main(){
    n=read();
    dfs(1);
    printf("%d\n",ans);
    system("pause");
    return 0;
}