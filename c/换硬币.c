#include<stdio.h>
int main()
{
int x;
scanf("%d",&x);
int cent5,cent2,cent1,p;
p = 0;
for(cent5=20;cent5>=1;cent5--){
    for(cent2=50;cent2>=1;cent2--){
        for(cent1=100;cent1>=1;cent1--){
            if(x==cent5*5+cent2*2+cent1*1){
                printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n",cent5,cent2,cent1,(cent5+cent2+cent1));
                p = p+1;
                }
            }
        }
    }
printf("count = %d",p);
return 0;
}