#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    int n; cin>>n;
    int suma=0,sumb=0,sumab=0,dexa=0,dexb=0,dexab=0;

    for(int i=1;i<=n;i++)
    {
        int a,b,c; cin>>a>>b>>c;

        if(a==1&&b==1)
        {
            suma++; sumb++; sumab++;
            if(c==1) { dexa++; dexb++; dexab++;}
        }
        else if(a==1)
        {
            suma++;
            if(c==1)  dexa++;
        }
        else if(b==1)
        {
            sumb++;
            if(c==1)  dexb++;
        }
    }

    double best=-1;
    if (suma>0) best=max(best,(double)dexa/suma);
    if (sumb>0) best=max(best,(double)dexb/sumb);
    if (sumab>0) best=max(best,(double)dexab/sumab);

    printf("%.2lf%\n",best*100);
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}