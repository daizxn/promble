#include<bits/stdc++.h>
using namespace std;

struct mark{
    int a,h;
};

mark p[5005];

bool cmp(mark x,mark y){
    if(x.a>y.a)return 1;
    if(x.a==y.a&&x.h<y.h)return 1;
    return 0;
}
int main(){
    int n,m,pass,num=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>p[i].h>>p[i].a;
    sort(p+1,p+n+1,cmp);
    pass=p[m*3/2].a;
    for(int i=1;i<=n;i++){
        if(p[i].a>=pass)
            num++;
    }
    cout<<pass<<' '<<num<<endl;
    for(int i=1;i<=num;i++){
        cout<<p[i].h<<' '<<p[i].a<<endl;
    }
    system("pause");
    return 0;
}