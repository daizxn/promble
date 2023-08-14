#include<bits/stdc++.h>
using namespace std;

int a[200000];

bool cmp(int x,int y){
    return x>y;
}

int main(){
    int n,b,sum=0;
    cin>>n>>b;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(sum>=b){
            cout<<i<<endl;
            break;
        }     
    }
    // system("pause");
    return 0;
}