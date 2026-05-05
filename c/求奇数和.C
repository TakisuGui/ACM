#include<stdio.h>
int main(){
int a=0,sum=0;
while(1){
    scanf("%d",&a);
    if(a<=0){
        break;
    }
    else if(a%2==0){
    }
    else{
        sum = sum + a;
    };
};
printf("%d",sum);
return 0;
}