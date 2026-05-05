#include<stdio.h>
int main()
{
int m,n;
scanf("%d %d",&m,&n);
int min=(m<n)?m:n;
int max=(m>n)?m:n;
for(int a=min;a>=1;a--){
    if (m%a==0&&n%a==0){
    printf("%d ",a);
    break;}
}
for(int b=max;b<=m*n;b++){
    if(b%m==0&&b%n==0){
        printf("%d",b);
        break;
    }
}
return 0;
}