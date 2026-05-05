#include<stdio.h>
#include<string.h>
int main()
{
char a[81];
int count[128]={0};
fgets(a,sizeof(a),stdin);
int len=strlen(a);
for(int i=0;a[i]!='\n';i++){
    count[(int)a[i]]=1;
}
for(int i=0;i<128;i++){
    if(count[i]==1){
        printf("%c",(char)i);
    }
}
return 0;
}