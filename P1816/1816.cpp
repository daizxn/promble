#include <iostream>
#include <algorithm>
#include <string.h>

const int N = 1e5;

class ST
{
private:
    int st[N][32];
    int lg[N];
    int size;
public:
    ST(int n)
    {
        size=n;
        memset(st, 0, sizeof(st));
        lg[0]=-1;
        for(int i=1;i<=n;i++)
            lg[i]=lg[i>>1]+1;
    }
    ST(int *arr,int n){
        size=n;
        lg[0]=-1;
        for(int i=1;i<=n;i++){
            st[i][0]=arr[i];
            lg[i]=lg[i>>1]+1;
        }
    }
    void build(){
        for(int j=1;j<=lg[size];j++)
            for(int i=1;i<=size-(1<<j)+1;i++)
                st[i][j]=std::max(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
    int query(int l, int r){
        int t=lg[r-l+1];
        return std::max(st[l][t],st[r-(1<<t)+1][t]);
    }
};

int main()
{
    int n,m;
    int arr[N];
    std::cin>>n>>m;
    for(int i=1;i<=n;i++)
        std::cin>>arr[i];
    ST st(arr,n);
    st.build();
    for(int i=1;i<=m;i++){
        int l,r;
        std::cin>>l>>r;
        std::cout<<st.query(l,r)<<' ';
    }
    system("pause");
    return 0;
}