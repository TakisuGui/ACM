#include<stdio.h>
void plus(int a[],int n);
int main()
{
int n,m;
while((scanf("%d %d",&n,&m))!=EOF){
int a[n];
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
for(int i=0;i<m-1;i++){
    plus(a,n);
}
int first=1;
for(int i=0;i<n;i++){
    if(first){
        printf("%d",a[i]);
        first=0;
    }
    else if(!first)
    printf(" %d",a[i]);
}
printf("\n");
}
return 0;
}
void plus(int a[],int n){
    for(int j=n-1;j>0;j--){
        if(a[j]<a[j-1]){
            int temp=a[j-1];
            a[j-1]=a[j];
            a[j]=temp;
        }
    }
}