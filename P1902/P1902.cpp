#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

const int N=1005;
const int inf=0x3f3f3f3f;

int n,m;
int p[N][N],v[N][N];
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};;

int read();
bool check(int x);

int main(){
    int l=inf,r=-inf,mid,ans;
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            p[i][j]=read();
            l=min(l,p[i][j]);
            r=max(r,p[i][j]);
        }    
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else 
            l=mid+1;
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}

int read(){
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

bool check(int val){
    memset(v,0,sizeof v);
    queue<P> q;
    q.push(make_pair(1,1));
    v[1][1]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx=x+d[i][0];
            int dy=y+d[i][1];
            if(dx<1||dy<1||dx>n||dy>m||p[dx][dy]>val||v[dx][dy])
                continue;
            v[dx][dy]=1;
            if(dx==n)
                return 1;
            else 
                q.push(make_pair(dx,dy));
        }
    }
    return 0;
}