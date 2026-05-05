#include<stdio.h>
int main()
{
int n,size;
scanf("%d %d",&n,&size);
int a[n];
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
int temp[size];
int q=0;
for(int p=size-1;p>=0;p--){
    temp[q++]=a[p];
}
for(int i=0;i<size;i++){
    a[i]=temp[i];
}
for(int i=0;i<n;i++){
    printf("%d ",a[i]);
}
return 0;
}