#include <stdio.h>
#include <string.h>
#include <math.h>

const int N=40;





int main()
{
    char text[N];
    fgets(text,sizeof(text),stdin);

    int ip1=0;
    for(int i=0;i<=7;i++)
    {
        if(text[i]=='1')
        ip1+=pow(2,8-i-1);
    }
    int ip2=0;
    for(int i=8;i<=15;i++)
    {
        if(text[i]=='1')
        ip2+=pow(2,8-i+7);
    }
    int ip3=0;
    for(int i=16;i<=23;i++)
    {
        if(text[i]=='1')
        ip3+=pow(2,8-i+15);
    }
    int ip4=0;
    for(int i=24;i<=31;i++)
    {
        if(text[i]=='1')
        ip4+=pow(2,8-i+23);
    }


    printf("%d.%d.%d.%d",ip1,ip2,ip3,ip4);

    return 0;
}