#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int a[n][n];
int num=1;
int top=0,bottom=n-1,left=0,right=n-1;
while(num<=n*n){
    for(int i=left;i<=right&&num<=n*n;i++){
        a[top][i]=num++;
    }
    top++;
    for(int i=top;i<=bottom&&num<=n*n;i++){
        a[i][right]=num++;
    }
    right--;
    for(int i=right;i>=left&&num<=n*n;i--){
        a[bottom][i]=num++;
    }
    bottom--;
    for(int i=bottom;i>=top&&num<=n*n;i--){
        a[i][left]=num++;
    }
    left++;
}
 for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
return 0;
}