#include<stdio.h>
int main()
{
int x,a,b,t,q;
t=q=0;
char are;
scanf("%d", &x);
q = x; 
while(scanf(" %c", &are) == 1 && are != '='){
      scanf("%d", &x);
      a=q;
      b=x;
      if(are=='+'){
        t=a+b;
      }
      else if(are=='-'){
        t=a-b;
      }
      else if(are=='*'){
        t =a*b;
      }
      else if(are=='/'){
        if(b==0){
            printf("ERROR");
            return 0;
        }
        else{
            t = a/b;
        }
      }
      else{
        printf("ERROR");
            return 0;
      }
      q=t;
    }
printf("%d",q);
return 0;
}

