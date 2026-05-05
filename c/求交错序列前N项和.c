#include<stdio.h>
#include<math.h>
int main()
{
int n,a;
double ans;
ans = 0;
scanf("%d",&n);
a=1;
while(a<=n){
    ans = ans + pow(-1,a+1)*a/(2*a-1);
    a = a+1;
}
printf("%.3lf",ans);
return 0;
}
