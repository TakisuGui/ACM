#include<bits/stdc++.h>
using namespace std;
using i128 =__int128_t;
const long long MOD=998244353;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) 
    {
        int n; long long x; cin>>n>>x;

        vector<long long> a(n);
        i128 total=0,F=0;
        vector<i128> costs;
        costs.reserve(n);

        for (int i=0; i<n;++i) 
        {
            cin>>a[i];
            total+=a[i];
            if (x==1) continue;
            F+=a[i]/x;
            long long r=a[i]%x;
            costs.push_back(x-r);
        }

        if (x==1) 
        {
            cout<<(long long)(total%MOD)<<'\n';
            continue;
        }

        sort(costs.begin(),costs.end());
        i128 Sn=0;
        for (i128 c : costs) Sn+=c;

        i128 m_inf=(F+(i128)x*n-Sn)/(x-1);
        i128 m;

        if (m_inf>=n) m=m_inf;
        else 
        {
            i128 S=0;
            m=0;
            for (int i=1; i<n;i++) 
            {
                S+=costs[i-1];
                if (S<=F+i) m=i;
            }
        }

        i128 k=F+m;
        i128 ans=total-(i128)(x-1)*k;
        cout<<(long long)(ans % MOD)<<'\n';
    }
    return 0;
}

