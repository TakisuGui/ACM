#include<stdio.h>
int main()
{
int year,b,a;
b=0;
scanf("%d",&year);
if(year>=2001&&year<=2100){
    for(a=2001;year>=a;a++){
        if((a%4==0&&a%100!=0)||a%400==0){
            b = b +1;
            if(b!=0){
                printf("%d\n",a);
           };
        };
    };
    if(b==0){
        printf("None");
  };
}
else{
    printf("Invalid year!");
};
return 0;
}