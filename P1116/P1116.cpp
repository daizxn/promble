#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
long long ans=0;
void msort(int l,int r){
    if(l==r)
        return;
        int m=(l+r)/2;
        int i=l,j=m+1,t=l;
        msort(l,m);msort(m+1,r);
        while(i<=m&&j<=r){
            if(a[i]<=a[j]){
                b[t++]=a[i++];
            }
            else{
                b[t++]=a[j++];
                ans+=m-i+1;
            }
        }
        while(i<=m)
			b[t++]=a[i++];
		while(j<=r)
			b[t++]=a[j++];
		for(int q=l;q<=r;q++)
			a[q]=b[q];
        return;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    msort(1,n);
    cout<<ans<<endl;
    system("pause");
    return 0;
}