#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int str[n][n];
for(int i=0;i<n;i++){
    for(int m=0;m<n;m++){
        scanf("%d",&str[i][m]);
    }
}
int found=0;
for(int i=0;i<n;i++){
    int max=str[i][0];
    int index=0;
    for(int m=1;m<n;m++){
        if(max<str[i][m]){
            max=str[i][m];
            index=m;
        }
    }
    for(int j=0;j<n;j++){
        if(str[i][j]==max){
    int is_min=1;
    for(int k=0;k<n;k++){
        if(str[k][j]<str[i][j]){
            is_min=0;
            break;
          }
    }
    if(is_min){
        printf("%d %d\n",i,j);
        found=1;
        break;
       }
      }  
    }
}
if(!found){
        printf("NONE\n");
    }
    
    return 0;
}