#include<stdio.h>
#include<math.h>
int main()
{
int n,a;
double h;
scanf("%lf %d",&h,&n);
double s = h;
if(n==0){
    printf("0.0 0.0");
}
else if (n==1){
    printf("%.1lf,0.0",h);
}
else{
    for(int a=1; a<n; a++){
     s = s + h * pow(0.5,a) *2;
    }
    printf("%.1lf %.1lf",s,h * pow(0.5,n));
}
return 0;
}