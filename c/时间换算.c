#include<stdio.h>
int main()
{
int hour,min,s;
scanf("%d:%d:%d",&hour,&min,&s);
int n;
scanf("%d",&n);
s=s+n;
if(s>=60){
    s=s-60;
    min=min+1;
}
if(min>=60){
    min=min-60;
    hour=hour+1;
}
if(hour>=24){
    hour=0;
}
if(hour<=9){
    printf("0%d:",hour);
}
else{
    printf("%d:",hour);
}
if(min<=9){
    printf("0%d:",min);
}
else{
    printf("%d:",min);
}
if(s<=9){
    printf("0%d",s);
}
else{
    printf("%d",s);
}
return 0;
}