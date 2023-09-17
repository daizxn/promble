#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int cf[N][N],t[N][N];
int main(){
    memset(cf,0,sizeof cf);
    memset(t,0,sizeof cf);
    int n,m;
    int x1,x2,y1,y2;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1;i<=x2;i++){
            cf[i][y1]++;
            cf[i][y2+1]--;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            t[i][j]=t[i][j-1]+cf[i][j];
            cout<<t[i][j]<<' ';
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}
