#include<stdio.h>
int main()
{
int n,a;
double sum;
sum = 0.0;
a = 1;
scanf("%d",&n);
while(a <=n)
{sum =sum + 1.0/a;
a =a +1;}
printf("sum = %.6lf",sum);
return 0;
}