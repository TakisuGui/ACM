#include<stdio.h>
#include<math.h>
int main()
{
int m,n;
double sum;
sum = 0.0;
scanf("%d %d",&m,&n);
while(m<=n){
    sum = sum + (pow(m,2)+1.0/m);
    m = m +1;
}
printf("sum = %.6lf",sum);
return 0;
}   