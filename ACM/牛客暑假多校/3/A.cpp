#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=1e5+10;
const int MOD=1e9+7;

ll cnt[30][4];

void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<n;i++)
    {
        for(int k=0;k<30;k++)
        {
            int bit_k=(1&(a[i]>>k));
            int bit_k1=(k+1<30 ? 1&(a[i]>>(k+1)) : 0);

            int state=(bit_k|(bit_k1<<1));
            cnt[k][state]++;
        }
    }


    int m; cin>>m;
    unsigned int mask0=0;
    unsigned int mask1=(1U<<30)-1;

    while(m--)
    {
        int type; cin>>type;
        unsigned int x; cin>>x;

        if(type==1){ mask0&=x; mask1&=x;}
        else if(type==2){ mask0|=x; mask1|=x;}
        else{ mask0^=x; mask1^=x;}


        ll total=0;
        for(int k=0;k<30;k++)
        {
            for(int s=0;s<4;s++)
            {
                if(cnt[k][s]==0) continue;

                int orig_k=s&1;
                int orig_k1=(s>>1)&1;

                int nk=(orig_k==1) ? ((mask1>>k)&1) : ((mask0>>k)&1);
                int nk1=0;
                if(k+1<30) nk1=(orig_k1==1) ? ((mask1>>(k+1))&1) : ((mask0>>(k+1))&1);

                if(nk==1&&nk1==0) total+=cnt[k][s];
            }
        }

        cout<<total<<endl;
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}
