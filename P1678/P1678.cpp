#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e5+5;

int a[N],b[N];

int main(){
    int n,m,ans;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++){
        int l=1,r=m;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[mid]<=b[i]){
                ans=mid;
                l=mid+1;
            }
            else {
                r=mid-1;
            }
        }
    }
}