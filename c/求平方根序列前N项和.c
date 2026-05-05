#include<stdio.h>
#include<math.h>
int main()
{
int n,a;
double m;
m =0;
scanf("%d",&n);
for(a=1;a<=n;a++){
    m =m + pow(a,0.5);
};
printf("sum = %.2lf",m);
return 0;
}
