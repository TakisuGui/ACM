#include<stdio.h>
int main()
{
char ch;
while((ch=getchar())!='\n'){
    if(ch>='a'&&ch<='z'){
        if(ch=='z'){
            putchar('A');
        }
        else{
            putchar(ch+1-32);
        } 
    }
    else if(ch>='A'&&ch<='Z'){
        if(ch=='Z'){
            putchar('a');
        }
        else{
            putchar(ch+1+32);
        }
    }
    else{
        putchar(ch);
    }
}
return 0;
}