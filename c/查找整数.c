#include<stdio.h>
int main()
{
int k,key;
scanf("%d",&k);
for(int i=0;i<k;i++){
    int n;
    scanf("%d %d",&n,&key);
    int std[n];
    for(int p=0;p<n;p++){
        scanf("%d",&std[p]);
    }
    int place=0;
    int apprance=0;
    for(int q=0;q<n;q++){
        if(std[q]==key){
            place=q;
            apprance=1;
            break;
        }
    }
    if(apprance){
        printf("%d\n",place+1);
    }
    else if(!apprance){
        printf("-1\n");
    }
}
return 0;
}