#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
char word[100],text[100];
fgets(word,sizeof(word),stdin);
fgets(text,sizeof(text),stdin);
word[strcspn(word,"\n")]='\0';
text[strcspn(text,"\n")]='\0';
for(int i=0;word[i];i++){
    word[i]=tolower(word[i]);
}
int len=strlen(text);
int p=0,q=-1;
for(int i=0;i<len;i++){
    if(text[i]==' ')
        continue;   
    int j=i;
    char temp[100];
    int idx=0;
    while(j<len&& text[j] != ' '){
        temp[idx++]=tolower(text[j++]);
    }
    temp[idx]='\0';
    if(strcmp(temp,word)==0){
        p++;
        if(q==-1){
            q=i;
        }
    }
    i=j;
 }
if (p > 0) {
        printf("%d %d\n", p, q);
    } else {
        printf("-1\n");
    }
    
    return 0;
}