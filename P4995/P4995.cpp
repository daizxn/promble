#include<bits/stdc++.h>
using namespace std;

const int N=305;

long long a[N];

int read(){
    int x=0,f=1;
    char ch=getchar();
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

int main(){
    int n;
    n=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    a[0]=0;
    sort(a,a+n+1);
    long long i=0,j=n,ans=0;
    while(i<j){
        ans+=(a[i]-a[j])*(a[i]-a[j]);
        i++;
        ans+=(a[i]-a[j])*(a[i]-a[j]);
        j--;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}