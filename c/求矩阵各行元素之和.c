#include<stdio.h>
int main()
{
int m,n;
scanf("%d %d",&m,&n);
int str[m][n];
for(int i=0;i<m;i++){
    for(int q=0;q<n;q++){
        scanf("%d",&str[i][q]);
    }
}
int s=0;
for(int i=0;i<m;i++){
    for(int q=0;q<n;q++){
        s=s+str[i][q];
        if(q==(n-1)){
            printf("%d\n",s);
            s=0;
            break;
        }
    }
}
return 0;
}