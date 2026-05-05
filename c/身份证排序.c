#include<stdio.h>
#include<string.h>
int main(){
     int n;
    scanf("%d", &n);
    char str[n][19];
    for(int i=0;i<n;i++){
        scanf("%s",str[i]);
    }
     for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1; j++){
            if(strncmp(str[j]+6,str[j+1]+6,8)>0){
                char temp[19];
                strcpy(temp,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],temp);
            }
        }
     }
    for(int i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }
    
    return 0;
}