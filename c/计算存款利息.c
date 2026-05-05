#include<stdio.h>
#include<math.h>
int main()
{
double money,year,rate,a;
scanf("%lf %lf %lf",&money,&year,&rate);
a = money * pow(1 + rate ,year) -money;
printf("interest = %.2lf",a);
return 0;
}

