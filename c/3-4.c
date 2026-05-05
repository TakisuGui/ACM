#include<stdio.h>
int main(){
int N ;
int m=0,a=0,b=0,c=0,d=0,e=0;
scanf("%d",&N);
int debts[N];
for(m=0;m<N;m++){
    scanf("%d",&debts[m]);
}
for(m=0;m<N;m++){
    if(debts[m]>=90&&debts[m]<=100){
    a =a+1;
 }
else if(debts[m]>=80&&debts[m]<90){
    b =b+1;
 } 
else if(debts[m]>=70&&debts[m]<80){
    c =c+1;
 }
else if(debts[m]>=60&&debts[m]<70){
    d =d+1;
 }
else{
    e =e+1;
 };
}
printf("%d %d %d %d %d",a,b,c,d,e);
return 0;
}
