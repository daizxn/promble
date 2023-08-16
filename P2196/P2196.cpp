#include<bits/stdc++.h>
using namespace std;
const int N=25;

int n,maxx,cnt;
int a[N],path[N],ans[N];
bool t[N][N],visit[N];//visit 0为没走过，1为走过

bool check(int v){//检测是否走到底
    for(int u=1;u<=n;u++)
        if(t[v][u])return false;
    return true;
}
void dfs(int v,int stp,int sum){//v号地窖，走了stp步，地雷总数为sum
    if(check(v)){//走到底
        if(sum>maxx){
            maxx=sum;
            cnt=stp;
            for(int i=1;i<=cnt;i++){
                ans[i]=path[i];
            }
        }
        return;
    }
    stp+=1;
    for(int u=1;u<=n;u++){
        if(t[v][u]&&!visit[u]){
            visit[u]=1;
            path[stp]=u;
            dfs(u,stp,sum+a[u]);
            visit[u]=0;
            path[stp]=0;
        }
    }
    return;
}
int main(){
    memset(visit,0,sizeof visit);
    memset(path,0,sizeof path);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            cin>>t[i][j];
    for(int i=1;i<=n;i++){
        visit[i]=1;
        path[1]=i;
        dfs(i,1,a[i]);
        path[1]=0;
        visit[i]=0;
    }
    for(int i=1;i<=cnt;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
    cout<<maxx<<endl;
    system("pause");
    return 0;
}

