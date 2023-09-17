#include<bits/stdc++.h>
using namespace std;

int dp[5010][5010];

int main(){
    int n,m;
    int x,y,v;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>v;
        dp[x+1][y+1]+=v;
    }
    int N=5001;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            dp[i][j]+=dp[i][j-1];
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            dp[i][j]+=dp[i-1][j];
    int ans=0;
    for(int i=m;i<=N;i++)
        for(int j=m;j<=N;j++){
            int sum=dp[i][j]-dp[i-m][j]-dp[i][j-m]+dp[i-m][j-m];
            ans=max(ans,sum);
        }
    cout<<ans<<endl;
    system("pause");
    return 0;
}