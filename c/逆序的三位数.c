#include<stdio.h>
int main()
{
int a,b,c,d;
scanf("%d",&a);
b = a/100;
c = (a-b*100) / 10;
d = a - b*100 - c*10;
if((d!=0&&c!=0) ||(d!=0&&c==0))
    printf("%d%d%d",d,c,b);
else if(c==0&&d==0)
    printf("%d",b);
else if(d==0&&c!=0)
printf("%d%d",c,b);
return 0;
}