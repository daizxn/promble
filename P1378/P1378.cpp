#include<bits/stdc++.h>
using namespace std;

int n;
int x_1,x_2,y_1,y_2;
double ans=0.0;

int x[10],y[10];
double r[10];
bool b[10];

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

int dd(int x){
    return x*x;
}

void dfs(int num,double area){
    if(num==n+1){
        ans=max(ans,area);
        return;
    }
    for(int i=1;i<=n;i++)
        if(!b[i]){
            int tt=0;
            for(int j=1;j<=n;j++)
                if(b[j]&&r[j]>=sqrt(dd(x[i]-x[j])+dd(y[i]-y[j]))){
                    b[i]=1;
                    tt=1;
                    dfs(num+1,area);
                    b[i]=0;
                }
            if(tt==1)continue;
            b[i]=1;
            r[i]=min(min(abs(x[i]-x_1),abs(x[i]-x_2)),min(abs(y[i]-y_1),abs(y[i]-y_2)));
            for(int j=1;j<=n;j++)
                if(j!=i&&b[j]){
                    double d=sqrt(dd(x[i]-x[j])+dd(y[i]-y[j]));
                    r[i]=min(r[i],d-r[j]);
                }
            dfs(num+1,area+M_PI*r[i]*r[i]);
            r[i]=0.0;
            b[i]=0;
        }
    return;
}

int main(){
    n=read();
    x_1=read()+1000;y_1=read()+1000;x_2=read()+1000;y_2=read()+1000;
    for(int i=1;i<=n;i++)
        x[i]=read()+1000,y[i]=read()+1000;
    dfs(1,0.0);
    ans=abs(x_1-x_2)*abs(y_1-y_2)-ans;
    int ANS=int(ans+0.5);
    cout<<ANS<<endl;
    system("pause");
    return 0;
}