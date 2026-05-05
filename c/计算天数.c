#include<stdio.h>
int main()
{
int year,month,day,t,s;
scanf("%d/%d/%d",&year,&month,&day);
if((year%4==0&&year%100!=0)||year%400==0){
    t=29;
}
else{
    t=28;
}
switch (month){
    case 1:s=0;
    break;
    case 2:s=31;
    break;
    case 3:s=31+t;
    break;
    case 4:s=31+t+31;
    break;
    case 5:s=31+t+31+30;
    break;
    case 6:s=31+t+31+30+31;
    break;
    case 7:s=31+t+31+30+31+30;
    break;
    case 8:s=31+t+31+30+31+30+31;
    break;
    case 9:s=31+t+31+30+31+30+31+31;
    break;
    case 10:s=31+t+31+30+31+30+31+31+30;
    break;
    case 11:s=31+t+31+30+31+30+31+31+30+31;
    break;
    case 12:s=31+t+31+30+31+30+31+31+30+31+30;
    break;
}
s=s+day;
printf("%d",s);
return 0;
}