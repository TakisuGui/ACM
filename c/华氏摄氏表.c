#include<stdio.h>
int main()
{
int upper, lower;
double a;
scanf("%d %d",&lower,&upper);
if(lower>upper||upper>100||lower>100){
printf("Invalid.");}
else
{
    printf("fahr celsius\n");
    while(lower<=upper)
    {
        a = 5.0*(lower-32)/9.0;
        printf("%d %6.1lf\n",lower,a);
        lower = lower + 2;
    }
}
return 0;
}