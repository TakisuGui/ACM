#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e3+10;

int v[N],w[N];

void solve()
{
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];

    int res=0;
    for(int i=30;i>=0;i--)
    {
        int target=res|(1<<i);

        bool first=true;
        int cur_v_and=0;
        bool found=false;

        for(int j=1;j<=n;j++)
        {
            if((w[j]&target)==target)
            {
                if(first)
                {
                    cur_v_and=v[j];
                    first=false;
                }
                else cur_v_and&=v[j];

                found=true;
            }
        }

        if(found&&cur_v_and<=k) res=target;
    }

    cout<<res<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}