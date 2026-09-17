#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    vector<pair<int,int>> has(2);

    while(cin>>has[0].first>>has[0].second>>has[1].first>>has[1].second)
    {
        sort(has.begin(),has.end());
        int m,n;
        int a=has[0].first,b=has[0].second,c=has[1].first,d=has[1].second;

        if(b<c) m=0,n=1;
        else if(a<c&&d<b)
        {
            m=1,n=b-a+1;
        }
        else
        {
            m=(b-c+1),n=(b-a+1)*(d-c+1);
            int p=__gcd(m,n);
            m/=p,n/=p;
        }
        cout<<m<<"/"<<n<<endl;
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
