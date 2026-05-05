#include<stdio.h>

const int N=1e5+10;
int n;
int e[N];
int ne[N];
int h=0,id=0;


void push(int i)
{
    id++;
    e[id]=i;

    ne[id]=ne[h];
    ne[h]=id;
}


void pop(int i)
{
    ne[i]=ne[ne[i]];
}


int main()
{
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++) push(i);
    ne[n]=ne[h];

    int temp=h;

    int tex=n;

    while(1)
    {
        temp=ne[temp];
        temp=ne[temp];

        pop(temp);
         tex--;

        if(tex==1)break;

    }

    for(int i=h;i;i=ne[i])
    printf("%d",e[i]);

    return 0;
}