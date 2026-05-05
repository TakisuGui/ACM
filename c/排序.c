#include<stdio.h>
int main()
{
int n,temp;
scanf("%d",&n);
int str[n];
for(int i=0;i<n;i++){
    scanf("%d",&str[i]);
}
for(int i=0;i<n;i++){
    int max_index=i;
    for(int p=i+1;p<n;p++){
        if(str[p]>str[max_index]){
            max_index=p;
        }
    }
    if(max_index!=i){
        temp=str[i];
        str[i]=str[max_index];
        str[max_index]=temp;
    }
}
for(int q=0;q<n;q++){
    printf("%d",str[q]);
    if(q<n-1){
        printf(" ");
    }
}
return 0;
}