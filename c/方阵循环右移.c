#include<stdio.h>
int main()
{
int n,m,a,b,t;
scanf("%d %d",&m,&n);
int debts[n][n];
int  new[n][n];
for(a=0;a<n;a++){
    for(b=0;b<n;b++){
        scanf("%d",&debts[a][b]);
        }
    }
m = m%n;
for(a=0;a<n;a++){
    for(b=0;b<n;b++){
        t = (b+m)%n;
        new[a][t]=debts[a][b];
    }
}
for(a=0;a<n;a++){
    for(b=0;b<n;b++){
        printf("%d ",new[a][b]);
        }
    printf("\n");
    }
return 0;
}
