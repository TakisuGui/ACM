#include<stdio.h>
int main()
{
double s,a,b;
int t;
a=b=0;
scanf("%lf %d",&s,&t);
if(s<=3){
    a = 10;
}
else if(3<s&&s<=10){
    a = 10 + (s-3)*2;
}
else{
    a = 10 + 14 + (s -10)*3;
};
if(t<5){
    b=0;
}
else{
    b=t/5*2;
};
printf("%.0lf",a+b);
return 0;
}