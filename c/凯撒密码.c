#include<stdio.h>
#include<string.h>
int main()
{
char str[82];
int offset;
fgets(str,sizeof(str),stdin);
scanf("%d",&offset);
int len=strlen(str);
 if(len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
        len--;
    }
for(int i=0;i<len;i++){
    if(str[i]>='A'&&str[i]<='Z'){
        str[i]=((str[i] - 'A' + offset) % 26 + 26) % 26 + 'A';
    }
    else if(str[i]>='a'&&str[i]<='z'){
        str[i]= ((str[i] - 'a' + offset) % 26 + 26) % 26 + 'a';
    }
}
printf("%s",str);
return 0;
}