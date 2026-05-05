#include<stdio.h>
#include<math.h>
int plus(int num, int n){
    int p = num;
    long long sum = 0;
    while(p>0){
        int x = p % 10;
        sum = sum + pow(x,n);
        p = p / 10;
    }
    return sum == num;
}
int main(){
    int n;
    scanf("%d",&n);
    int from = pow(10,n-1);
    int to   = pow(10,n);
    for(int num=from;num<=to;num++){
        if(plus(num,n)){
            printf("%d\n",num);
        }
    }
return 0;
}


