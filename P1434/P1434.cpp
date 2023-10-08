#include<stdio.h>
#include<stdlib.h>

const int N=105;

int n,m,e[N][N],a[N][N],ans;
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

inline int read(){
    int f=1,x=0;
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
int dfs(int x,int y){
    if(a[x][y])return a[x][y];
    int cur=1;
    for(int i=0;i<4;i++){
        int dx=x+d[i][0];
        int dy=y+d[i][1];
        if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&e[x][y]>e[dx][dy]){
            int temp=dfs(dx,dy)+1;
            if(temp>cur)
                cur=temp;
        }
    }
    a[x][y]=cur;
    return cur;
}
inline void print(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)print(x/10);
    putchar(x%10+'0');
}

int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            e[i][j]=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int temp=dfs(i,j);
            a[i][j]=temp;
            if(temp>ans)
                ans=temp;
        }
    print(ans);
    puts("");
    // system("pause");
    return 0;
}