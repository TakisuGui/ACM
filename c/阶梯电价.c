#include<stdio.h>
int main()
{
int a;
scanf("%d",&a);
if(a<0){
    printf("Invalid Value!");
}
else if(0<=a&&a<=50){
    printf("cost = %.2lf",(0.53*a));
}
else{
    printf("cost = %.2lf",(26.5+(a-50)*0.58));
}
return 0;
}