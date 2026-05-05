#include<stdio.h>
int main()
{
int n,temp,a,b,c,d,e,f,g,h,i,j;
scanf("%d",&n);
int str[n];
int plus[10];
for(int k=0;k<10;k++){
    plus[k]=0;
}
for(int i=0;i<n;i++){
    scanf("%d",&str[i]);
}
for(int i=0;i<n;i++){
    if(str[i]==0){
        plus[0]++;
        continue;
    }

    while(str[i]>0){
        temp=str[i]%10;
        str[i]=str[i]/10;
        switch(temp){
            case 0:plus[0]++;
            break;
            case 1:plus[1]++;
            break;
            case 2:plus[2]++;
            break;
            case 3:plus[3]++;
            break;
            case 4:plus[4]++;
            break;
            case 5:plus[5]++;
            break;
            case 6:plus[6]++;
            break;
            case 7:plus[7]++;
            break;
            case 8:plus[8]++;
            break;
            case 9:plus[9]++;
            break;
        }
    }
}
int max_index=0;
for(int i=0;i<10;i++){
    if(plus[i]>max_index){
        max_index=plus[i];
    }
}
printf("%d:", max_index);
int first=1;
for(int i=0;i<10;i++){
    if(max_index==plus[i]){
        if(first){
            printf(" %d",i);
            first=0;
        }
        else{
            printf(" %d",i);
        }
    }
}
return 0;
}
