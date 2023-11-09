#include<iostream>

using namespace std;

const int N=105;

int dp[N][N],M[N],T[N];

int main(){
    int n,m,t;
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++)
        cin>>M[i]>>T[i];
    for(int i=1;i<=n;i++)
        for(int j=m;j>=M[i];j--)
            for(int k=t;k>=T[i];k--)
                dp[j][k]=max(dp[j][k],dp[j-M[i]][k-T[i]]+1);
    cout<<dp[m][t]<<endl;
    system("pause");
    return 0;
}