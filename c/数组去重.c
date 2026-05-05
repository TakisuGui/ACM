#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
int t=n;
for(int p=0;p<n-1;p++){
    for(int i=p+1;i<n;i++){
        if(a[p]==a[i]){
            t--;
            break;
        }
    }
}
printf("%d",t);
return 0;
}