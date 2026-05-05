#include<stdio.h>
#include<ctype.h>
int main(){
char debts[10];
int a,b,c,d,e;
b=c=d=e=0;
for(a=0;a<10;a++){
    scanf("%c",&debts[a]);
};
for(a=0;a<10;a++){
    if(isalpha(debts[a])!=0){
        b = b+1;
    }
    else if(isspace(debts[a])!=0){
        c = c+1;
    }
    else if(isdigit(debts[a])!=0){
        d = d+1;
    }
    else{
        e =e+1;
    };
};
printf("letter = %d, blank = %d, digit = %d, other = %d",b ,c,d,e);
return 0;
}

