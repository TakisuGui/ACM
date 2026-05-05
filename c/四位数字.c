#include<stdio.h>
int plus(int i);
int sub16(int i);
int sub12(int i);
int main()
{
for(int i=1000;i<=9999;i++){
    if((plus(i)==sub16(i))&&(sub16(i)==sub12(i))){
        printf("%d\n",i);
    }
}
return 0;
}
int plus(int i){
    int s=0;
    int t=0;
    while(i>=1){
        t=i%10;
        i=i/10;
        s=s+t;
    }
    return s;
}
int sub16(int i){
    int p=0;
    int t=0;
    while(i>=1){
        t=i%16;
        i=i/16;
        p=p+t;
    }
    return p;
}
int sub12(int i){
    int m=0;
    int t=0;
    while(i>=1){
        t=i%12;
        i=i/12;
        m=m+t;
    }
    return m;
}