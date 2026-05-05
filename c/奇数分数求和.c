#include<stdio.h>
int main()
{
int n,a;
double sum;
scanf("%d",&n);
a =1;
sum = 0.0;
while(a<=(2 * n -1))
{
 sum = sum + 1.0/a;
 a = a + 2;   
}
printf("sum = %.6lf",sum);
return 0;
}
