#include<stdio.h>
int main()
{
int a[1000];
int num;
int i;
for(i=0;scanf("%d",&num)!=EOF;i++){
    a[i]=num;
}
int max_num = a[0]; 
int max_count = 0;  
for(int p=0;p<i;p++){
    int count =0;
    for(int j = 0; j < i; j++) {
            if(a[p] == a[j]) {
                count++;
            }
        }
        if(count > max_count) {
            max_count = count;
            max_num = a[p];
        }
}
printf("%d %d\n", max_num, max_count);
    
    return 0;
}