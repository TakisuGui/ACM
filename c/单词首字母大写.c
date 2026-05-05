#include<stdio.h>
int main()
{
char ch;
ch = getchar();
if(ch>='a'&&ch<='z'){
        putchar(ch-32);
        }
else{
        putchar(ch);
}
while(1){
    ch=getchar();
    if(ch=='\n'){
        break;
    }
      if(ch==' '){
        putchar(ch);
        ch = getchar();
      if(ch=='\n'){
        break;
        }
      if(ch>='a'&&ch<='z'){
        putchar(ch-32);
        }
      else{
        putchar(ch);
        }
    }
    else{
        putchar(ch);
    }
}
return 0;
}




