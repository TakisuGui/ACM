#include<stdio.h>
int main()
{
int n,month=1;
int month1=1,month2=0,month3=0;
scanf("%d",&n);
if(n==1){
    printf("1");
}
else {while(1){
    month3=month3+month2;
    month2=month1;
    month1=month3;
    month++;
    if(month1+month2+month3>=n){
        break;
             }
        }
    printf("%d",month);
}
return 0;
}