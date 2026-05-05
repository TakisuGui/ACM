#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;
const int MOD=998244353;
const int P=13331;
const int INF=0x3f3f3f3f;
const double EPS=1e-6;

void untie()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m; cin>>n>>m;
        vector<pair<ll ,ll>> a(n);

        if (n==1)
        {
            cout<<(m>0?1:0) <<'\n';
            continue;
        }

        for(int i=0;i<n;i++) cin>>a[i].second;
        for(int i=0;i<n;i++) cin>>a[i].first;
        sort(a.begin(),a.end()); 

          

        vector<ll> seg;
        int down_count=1;
        ll max_reach=a[0].first+a[0].second;

        for(int i=1;i<n;i++)
        {
            if(a[i].first<=max_reach)
            {
                down_count++;
                max_reach=max(max_reach,a[i].first+a[i].second);
            }
            else
            {
                seg.push_back(down_count);
                down_count=1;
                max_reach=a[i].first+a[i].second;
            }
        }
        seg.push_back(down_count);

        ll ans=0;
        sort(seg.rbegin(),seg.rend());
        for(int i=0;i<min(m,(int)seg.size());i++)
        {
            ans+=seg[i];
        }

        cout<<ans<<'\n';


    }

    return 0;
}