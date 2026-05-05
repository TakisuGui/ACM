#include<stdio.h>
#include<math.h>
int main()
{
double S,a,n;
S=0;
scanf("%lf",&n);
if(n>=1.0){
     printf("sum = 1.000000");
     return 0;
};
for(a=1; 1.0/(3*a-2) >= n;a++){
    S = S + 1.0/(3*a-2)*pow(-1,a+1);
};
printf("sum = %.6lf",S);
return 0;
}