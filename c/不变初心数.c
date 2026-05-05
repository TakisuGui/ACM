#include<stdio.h>
int main(){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
    int t;
    scanf("%d",&t);
    int sum=0;
    int temp=t;
    int ture=1;
    while(temp>0){
        int s=temp%10;
        temp=temp/10;
        sum=sum+s;
    }
    for(int q=2;q<=9;q++){
        int y=0;
        int plus=t;
        plus=plus*q;
        while(plus>0){
        int r=plus%10;
        plus=plus/10;
        y=y+r;
        }
        if(y!=sum){
            ture=0;
            break;
        }
    }
    if(ture){
        printf("%d\n",sum);
    }
    else{
        printf("NO\n");
    }
} 
return 0;
}