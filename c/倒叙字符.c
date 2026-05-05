#include<stdio.h>
int main()
{
int n,a;
scanf("%d",&n);
int debts[n];
for(a=0;a<n;a++){
    scanf("%d",&debts[a]);
}
for(a=n-1;a>=0;a--){
    if(a==0){
        printf("%d",debts[a]);
    }
    else{
        printf("%d ",debts[a]);
    }
}
return 0;
}
