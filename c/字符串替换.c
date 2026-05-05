#include <stdio.h>
#include <string.h>
int main(){
    char str[82];
    fgets(str,sizeof(str),stdin);
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]>='A'&&str[i]<='Z'){
            str[i]='A'+'Z'-str[i];
        }
    }
printf("%s",str);
return 0;
}