#include<stdio.h>
#include<math.h>
double plus(int a);
int main()
{
double n,ans,a;
scanf("%lf",&n);
ans = a = 1;
do{
    ans = ans + pow(n,a)/plus(a);
    a++;
}while(pow(n,a-1)/plus(a-1)>=0.00001);
printf("%.4lf",ans);
return 0;
}


double plus(int a)
{
double i,s;
s=1;
if(a>0){
for(i =1;i <=a;i++)
{
  s = s *i;
};
return s;}
else if(a==0){
    return 1;
};
}