#include<stdio.h>
#include<math.h>
int main()
{
int n,a,s;
scanf("%d",&n);
a =0;
while (a <= n)
{
s = pow (3,a);
printf("pow(3,%d) = %d\n",a ,s);
a = a +1;
}
return 0;
}