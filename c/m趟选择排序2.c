#include<stdio.h>
void plus(int a[],int n,int m);
int main()
{
char ch;
int n,m;
while((scanf("%d %d",&n,&m))!=EOF){
int a[n];
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
plus(a,n,m);
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
void plus(int a[],int n,int m){
    for(int p=0;p<m;p++){
    int t=p;
    int min=a[p];
    
    for(int i=p+1;i<n;i++){
        if(min>a[i]){
            min=a[i];
            t=i;
        }
    }
    if(t!=p){
    int temp=a[t];
    a[t]=a[p];
    a[p]=temp;
     }
}
}