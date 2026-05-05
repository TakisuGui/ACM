#include<stdio.h>
void sort(int a[], int l, int r);
int main()
{
int n,l,r;
scanf("%d %d %d",&n,&l,&r);
int a[n];
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
sort( a, l, r);
for(int i=0;i<n;i++){
    printf("%d ",a[i]);
}
return 0;
}
void sort(int a[], int l, int r){
    for(int p=l;p<=r;p++){
        for(int j=l;j<r;j++){
            if(a[j]>a[j+1]){
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
}