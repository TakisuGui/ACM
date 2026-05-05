#include<stdio.h>
#include <string.h>
int main()
{
char str[5][80];
char temp[80];
for(int i=0;i<5;i++){
    scanf("%s", &str[i][0]);
}
for(int i = 0; i < 4; i++) {  
    for(int j=0;j<4;j++){
        if(strcmp((str[j]),str[j+1])>0){
            strcpy(temp,str[j]);
            strcpy(str[j],str[j+1]);
            strcpy(str[j+1],temp);
        }
    }
}
printf("After sorted:\n");
for(int i=0;i<5;i++){
    printf("%s\n",str[i]);
}
return 0;
}