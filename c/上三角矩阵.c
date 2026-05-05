#include<stdio.h>
int main()
{
int T;
scanf("%d",&T);
for(int p=1;p<=T;p++){
int n;
scanf("%d",&n);
int str[n][n];
for(int i=0;i<n;i++){
    for(int m=0;m<n;m++){
        scanf("%d",&str[i][m]);
    }
}
int plus=0;
if(n==1){
    printf("YES\n");
}
else if(n==2){
    if(str[1][0]==0){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
else{
for(int i=1;i<n;i++){
    for(int m=0;m<n-1;m++){
        if(str[i][m]==0){
            plus=1;
        }
        else{
            plus=0;
            break;
        }
    }
}
if(plus==1){
    printf("YES\n");
}
else{
    printf("NO\n");
}
}
}
return 0;
}
