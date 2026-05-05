#include<stdio.h>
int main()
{
int n,a,min;
scanf("%d",&n);
int debts[n];
for(a=0;a<n;a++){
    scanf("%d",&debts[a]);
};
min = debts[0];
for(a=1;a<n;a++){
    if(debts[a]<min){
        min = debts[a];
      }  
    };
printf("min = %d",min);
return 0;
}
