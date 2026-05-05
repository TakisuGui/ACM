#include<stdio.h>
#include<math.h>
int main()
{
double x,b;
scanf("%lf",&x);
b = ((x+1)*(x+1)+2*x+1/x);
if(x>=0)
printf("f(%.2lf) = %.2lf",x,pow(x,0.5));
else if(x<0)
printf("f(%.2lf) = %.2lf",x,b);
return 0;
}