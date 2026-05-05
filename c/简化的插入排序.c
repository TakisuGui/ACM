#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
if(n==0){
    int q;
    scanf("%d",&q);
    printf("%d ",q);
    return 0;
}
int a[n];
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
int q;
scanf("%d",&q);
int p=n+1;
int str[p];
if(a[0]>=q){
    str[0]=q;
    for(int i=1;i<p;i++){
        str[i]=a[i-1];
    }
}
else if(a[n-1]<=q){
    for(int i=0;i<n;i++){
        str[i]=a[i];
    }
    str[n]=q;
}
else{
    int w=0;
    for(w=0;a[w]<=q;w++){
            str[w]=a[w];
    }
    str[w]=q;
    w++;
    for(;w<p;w++){
        str[w]=a[w-1];
    }
}
for(int i=0;i<p;i++){
    printf("%d ",str[i]);
}
return 0;
}