#include<stdio.h>
int main()
{
char ch,a;
int b=0,x=-1,m=0;
scanf("%c",&a);
ch=getchar();
while((ch=getchar())!='\n'){
    if(ch==a){
        x=b;
    }
    else{
        m=1;
    }
    b++;
}
if(x>=0){
    printf("index = %d",x);
}
else if(x==-1&&m==1){
    printf("Not Found");
}
return 0;
}
