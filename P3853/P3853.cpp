#include<iostream>

using namespace std;

int place[100005];
int L,N,K;

bool check(int x){
    int site=0,k=K;
    for(int i=1;i<=N;i++){
        if(k<0)break;
        if(place[i]-site>x){
            site=site+x;
            k--;
             i--;
        }
        else{
            site=place[i];
        }
    }
    if(k>=0)return 1;
    else return 0;
}

int main(){
    cin>>L>>N>>K;
    for(int i=1;i<=N;i++)
        cin>>place[i];
    int l=0,r=L,ans;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;
}