#include<stdio.h>
int main(){
int N,a,b;
double e,c;
c=0,b=0,e =0;
scanf("%d",&N);
if(N!=0){
int debts[N];
for(a=0;a<N;a++){
    scanf("%d",&debts[a]);
}
for(a=0;a<N;a++){
    c = c + debts[a];
}
e = c / N;
printf("average = %.1lf\n",e);
for(a =0;a<N;a++){
    if(debts[a]>=60){
        b = b+1;
    }
  }
printf("count = %d\n",b);
}
else{
    printf("average = 0.0\ncount = 0");
};
return 0;
}


