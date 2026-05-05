#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int a=1;
for(int turn=1;turn<=n-1;turn++){
    a = (a+1)*2;
}
printf("%d",a);
}