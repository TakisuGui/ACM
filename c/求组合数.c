#include<stdio.h>
double plus(int a);
int main()
{
int m,n;
double ans;
scanf("%d %d",&m,&n);
ans = plus(n)/plus(m)/plus(n-m);
printf("result = %.0f",ans);
return 0;
}

double plus(int a)
{
double i,s;
s=1;
for(i =1;i <=a;i++)
{
  s = s *i;
};
return s;
}