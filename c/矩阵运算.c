#include<stdio.h>
int main()
{
int n,a,b,s=0;
scanf("%d",&n);
int debts[n][n];
for(a=0;a<n;a++){
    for(b=0;b<n;b++){
        scanf("%d",&debts[a][b]);
        }
    }
for(a=0;a<n;a++){
    for(b=0;b<n;b++){
        if(a+b==n-1){

        }
        else if(a==n-1){

        }
        else if(b==n-1){

        }
        else{
            int p=debts[a][b];
            s = s + p;
        }
    }
}
printf("%d",s);
return 0;
}