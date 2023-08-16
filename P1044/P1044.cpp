#include<bits/stdc++.h>
using namespace std;

int arr[25][25];

int f(int a,int b){//a为未入栈的个数，b为栈中的个数
    if(a==0&&b==0)return 1;
    if(arr[a][b])return arr[a][b];
    int ans=0;
    if(a>0)ans+=f(a-1,b+1);//一个数入栈
    if(b>0)ans+=f(a,b-1);//出栈
    arr[a][b]=ans;
    return ans;
}

int main(){
    memset(arr,0,sizeof arr);
    int n;
    cin>>n;
    int res=0;
    res=f(n,0);
    cout<<res<<endl;
    system("pause");
    return 0;
}