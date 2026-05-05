#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int m;
for(int i=0;i<n;i++){
    scanf("%d",&m);
    int a = m / 100000;            
    int b = (m/ 10000) % 10;      // 第二位
    int c = (m / 1000) % 10;       // 第三位
    int d = (m/ 100) % 10;        // 第四位
    int e = (m/ 10) % 10;         // 第五位
    int f = m % 10; 
    int p=a+b+c;
    int q=e+d+f;
    if(p==q){
        printf("You are lucky!\n");
    }
    else{
        printf("Wish you good luck.\n");
    }
}
return 0;
}