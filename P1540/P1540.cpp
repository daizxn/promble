#include<iostream>
#include<queue>
using namespace std;

bool in[1005];

int main(){
    int n,m,ans=0;
    cin>>m>>n;
    queue<int> q;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(in[x])
            continue;
        else{
            ans++;
            if(q.size()>=m){
                int t=q.front();
                in[t]=0;
                q.pop();
                q.push(x);
                in[x]=1;
            }
            else{
                q.push(x);
                in[x]=1;
            }
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}