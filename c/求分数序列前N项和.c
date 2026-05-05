#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int a=2,b=3,c=1,d=2;
int m,turn,t;
double sum=3.50;
turn=1;
if(n==1){
    printf("2.00");
    return 0;
}
else if (n==2){
    printf("3.50");
    return 0;
}
else{
    do{
                sum = sum + (double)(a+b)/(c+d);
                m = b;
                b = a + b;
                a = m;
                t = d;
                d = c+ d;
                c = t;
                turn++;}while(turn<=n-2);
    }
    printf("%.2lf",sum);
    return 0;
}