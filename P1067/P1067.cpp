#include <bits/stdc++.h>
using namespace std;
int n,a[101];
bool cnt=false;
int main(){
    scanf("%d",&n);
    for(int i=n;i>=0;i--){
        scanf("%d",&a[i]);
    }
 
    for(int i=n;i>=1;i--){
        if(a[i]!=0){
            if(i!=1){
	            if(a[i]>0){
                    if(cnt&&a[i]==1){
                        printf("+x^%d",i);
                    }
                    else if(cnt&&a[i]!=1){
                    	printf("+%dx^%d",a[i],i);
			    	}
			    	else if(!cnt&&a[i]==1){
				    	printf("x^%d",i);
				    }
                    else{
                        printf("%dx^%d",a[i],i);
                    }
                }
                else{

                	if(a[i]==-1){
                		printf("-x^%d",i);
			    	}
			    	else{
			    		printf("%dx^%d",a[i],i);
			    	}
                }
            }
            else{
            	if(a[i]>0){
            		if(cnt&&a[i]==1){
	                	printf("+x");
				    }
				    else if(cnt&&a[i]!=1){
				    	printf("+%dx",a[i]);
					}
					else if(!cnt&&a[i]==1){
						printf("x");
					}
					else{
						printf("%dx",a[i]);
					}
				}
	            else{
	            	if(a[i]==-1){
	            		printf("-x");
					}
					else{
						printf("%dx",a[i]);
					}
				}
            }
			cnt=true;//记录cnt为true
        }
    }

    if(a[0]>0&&!cnt){
        printf("%d",a[0]);
    }
    else if(a[0]>0&&cnt){
        printf("+%d",a[0]);
    }
    else if(a[0]!=0){
        printf("%d",a[0]);
    }
    return 0;
}