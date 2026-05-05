#include<stdio.h>
int plus(int a);
int main()
{
int m,n,ans;
ans = 0;
scanf("%d",&n);
for(m=1;m<=n;m++){
    ans = ans + plus(m);
};
printf("%d",ans);
return 0;
}

int plus(int a)
{
int b,c;
c =1;
for(b=1;b<=a;b++){
    c = c*b;
};
return c;
}
