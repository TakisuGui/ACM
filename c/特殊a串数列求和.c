#include<stdio.h>
#include<math.h>
int main()
{
int a,n,s,t,p;
s = p = 0;
scanf("%d %d",&a,&n);
for(t=1;t<=n;t++){
    p = p + pow(10,t-1)*a;
    s = s + p;
}
printf("s = %d",s);
return 0;
}