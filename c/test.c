#include <stdio.h>

const int N=1e5-10;

int n,m;

int main()
{
    scanf("%d %d",&n,&m);

    int queue[N];
    int start=0,end=0;
    for(int i=1;i<=n;i++)
    {
        queue[end]=i;
        end=(end+1)%N;
    }

    int count=0;
    int size=n;

    while(size>1)
    {
        count++;

        int out=queue[start];
        start=(start+1)%N;

        if(count==m)
        {
            count=0;
            size--;
        }
        else
        {
            queue[end]=out;
            end=(end+1)%N;
            
        }

    }
    printf("%d\n", queue[start]);

    return 0;
}
   