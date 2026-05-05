#include<stdio.h>
int main()
{
double a;
scanf("%lf",&a);
if(a==0)
printf("f(%.1lf)=0",a);
else if(a!=0)
printf("f(%.1lf)=%.1lf",a,(1/a));
return 0;
}
