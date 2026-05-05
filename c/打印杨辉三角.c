#include<stdio.h>
int plus(int a){
int i,s;
s=1;
if(a==0){
    return 1;
}
for(i=1;i<=a;i++)
{
s = s*i;
};
return s;
}
int main(){
int n;
scanf("%d",&n);
int temp=n;
for(int i=1;i<=n;i++){
    for(int q=temp-1;q>=1;q--){
        printf(" ");
    }
    temp--;
    if(i==1){
        printf("   1\n");
    }
    else if(i>1){
        for(int p=0;p<=i-1;p++){
            int s;
            s=plus(i-1)/plus(p)/plus(i-1-p);
            printf("%4d",s);
        }
        printf("\n");
    }
}
return 0;
}