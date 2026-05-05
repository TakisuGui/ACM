#include<stdio.h>
#include<math.h>
int main()
{
int n,a,b;
double sum;
scanf("%d",&n);
a =1, b =0;
sum = 0.0;
while(a<=(3 * n-2))
{
    sum = sum + 1.0/a * pow(-1,b);
    a = a+3;
    b = b +1;
};
printf("sum = %.3lf",sum);
return 0;
}