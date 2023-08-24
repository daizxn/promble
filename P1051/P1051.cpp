#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string name,max_name;
    int score1,score2,money=0,max_money=0,sum=0,x;
    char a,b;
    cin>>n;
    for(int i=1;i<=n;i++){
        money=0;
        cin>>name>>score1>>score2>>a>>b>>x;
        if(score1>80&&x>0)
            money+=8000;
        if(score1>85&&score2>80)
            money+=4000;
        if(score1>90)
            money+=2000;
        if(score1>85&&b=='Y')
            money+=1000;
        if(score2>80&&a=='Y')
            money+=850;
        sum+=money;
        if(money>max_money){
            max_name=name;
            max_money=money;
        }
    }
    cout<<max_name<<endl<<max_money<<endl<<sum<<endl;
    system("pause");
    return 0;;
}