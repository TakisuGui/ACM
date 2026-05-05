#include<stdio.h>
int main()
{
int n,a,max,t;
scanf("%d",&n);
int debts[n];
for(a=0;a<n;a++){
    scanf("%d",&debts[a]);
}
max = debts[0];
t = 0;
for(a=1;a<n;a++){
    if(max<debts[a]){
        max=debts[a];
        t=a;
    }
}
printf("%d %d",max,t);
return 0;
}

