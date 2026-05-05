#include <stdio.h>
#include <string.h>
#include <ctype.h>
int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
int main(){
char text[1000];
char temp[100];
char longest[100];
while(fgets(text,sizeof(text),stdin)){
    int i=0,j=0,t=0;
    while(text[i]!=' '&& text[i]!='\n' && text[i]!='\0'){
        if(is_letter(text[i])){
            while(is_letter(text[i])){
            longest[j++]=text[i++];
            }
        longest[j] = '\0';
        break;  
        } 
        else {
            i++;  
        }
    }
    while(text[i]!='\0'){
         if(is_letter(text[i])){
        t=0;
        while(is_letter(text[i])){
            temp[t++]=text[i++];
        }
        temp[t] = '\0'; 
        if(t>j){
            strcpy(longest,temp);
            j=t;
        }
      }
      else {
                i++;  
            }
    }
    printf("%s\n",longest);
}
return 0;   
}