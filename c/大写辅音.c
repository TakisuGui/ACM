#include<stdio.h>
int main()
{
int ch;
int s=0;
while((ch=getchar())!='\n'){
    if(ch>'A'&&ch<='Z'&&ch!='E'&&ch!='I'&&ch!='O'&&ch!='U'){
        s=s+1;
    }
}
printf("%d",s);
return 0;
}