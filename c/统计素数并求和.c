#include<stdio.h>
int main()
{
int M,N;
scanf("%d %d",&M,&N);
int a,b,c,e,p;
b=c=p=0;
for(a=M;a<=N;a++){ 
    if (a<2){
        p =0;
    }
    else{
        p=1;
    for(e=2;e<=a-1;e++){
               if(a%e==0){
                  p=0;
                  break;
                }
               else{
                  p=1;
                };
            };
        }   
    if(p==1){
        c=c+1;
        b=b+a;
    };
};
printf("%d %d",c,b);
return 0;
}
