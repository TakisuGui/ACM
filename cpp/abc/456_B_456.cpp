#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dex1_3,dex1_4,dex1_5,dex2_3,dex2_4,dex2_5,dex3_3,dex3_4,dex3_5;

int main()
{
    for(int i=1;i<=6;i++)
    {
        int x; cin>>x;
        if(x==4) dex1_3++;
        else if(x==5) dex1_4++;
        else if(x==6) dex1_5++;
    }
    for(int i=1;i<=6;i++)
    {
        int x; cin>>x;
        if(x==4) dex2_3++;
        else if(x==5) dex2_4++;
        else if(x==6) dex2_5++;
    }
    for(int i=1;i<=6;i++)
    {
        int x; cin>>x;
        if(x==4) dex3_3++;
        else if(x==5) dex3_4++;
        else if(x==6) dex3_5++;
    }

    double way=dex1_3*dex2_4*dex3_5
              +dex1_3*dex2_5*dex3_4
              +dex1_4*dex2_3*dex3_5
              +dex1_4*dex2_5*dex3_3
              +dex1_5*dex2_3*dex3_4
              +dex1_5*dex2_4*dex3_3;

    double ans=way/216.0;

    printf("%.10lf\n",ans);

    return 0;
}