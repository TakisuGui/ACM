#include<stdio.h>
int main()
{
int i,j;
scanf("%d %d",&i,&j);
int a[i][j];
for(int q=0;q<i;q++){
    for(int p=0;p<j;p++){
        scanf("%d",&a[q][p]);
    }
}
int found=0;
for(int q=1;q<i-1;q++){
    for(int p=1;p<j-1;p++){
        if(a[q][p]>a[q-1][p]&&a[q][p]>a[q+1][p]&&a[q][p]>a[q][p-1]&&a[q][p]>a[q][p+1]){
            printf("%d %d %d\n",a[q][p],q+1,p+1);
            found=1;
        }
    }
}
if(found==0){
    printf("None %d %d",i,j);
}
return 0;
}