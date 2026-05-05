#include<stdio.h>
#include<math.h>
int main()
{
double a,b,c;
double ans1,ans2;
scanf("%lf %lf %lf",&a,&b,&c);
double delta;
if(a==b&&b==c&&c==0){
    printf("Zero Equation");
    return 0;
}
if(a==b&&b==0&&c!=0){
    printf("Not An Equation");
    return 0;
}
if(a==0){
    printf("%.2lf",(-1)*c/b);
    return 0;
}
delta=pow(b,2)-4*a*c;
if(fabs(delta)<0.0000001){
    delta=0;
}
if(delta==0){
    ans1=(-1*b)/(2*a);
    printf("%.2lf",ans1);
}
else if(delta>0){
    ans1=(-1*b+pow(delta,0.5))/(2*a);
    ans2=(-1*b-pow(delta,0.5))/(2*a);
    printf("%.2lf\n%.2lf",ans1,ans2);
}
else{
    delta=(-1)*delta;
    double r=(-1*b)/(2*a);
    double i=pow(delta,0.5)/(2*a);
    if(r==0){
        printf("0.00+%.2lfi",i);
        printf("\n");
        printf("0.00-%.2lfi",i);
        return 0;
    }
    printf("%.2lf+%.2lfi",r,i);
    printf("\n");
    printf("%.2lf-%.2lfi",r,i);
}
return 0;
}