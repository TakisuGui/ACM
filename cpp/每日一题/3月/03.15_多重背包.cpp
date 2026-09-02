#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,m; cin>>n>>m;

        vector<pair<int,int>> item;
        int item_dex=0;

        for(int i=1;i<=n;i++)
        {
            int w,v,s; cin>>w>>v>>s;
            for(int k=1;k<=s;k*=2)
            {
                item.push_back({k*w,k*v});
                item_dex++;
                s-=k;
            }
            if(s>0)
            {
                item.push_back({s*w,s*v});
                item_dex++;
            }
        }

        vector<ll> dp(m+1,0);
        for(int i=0;i<=item_dex;i++)
        {
            int vol=item[i].first;
            int val=item[i].second;

            for(int j=m;j>=0;j--)
            {
                if(j>=vol) dp[j]=max(dp[j],dp[j-vol]+val);
                else break;
            }
        }
        cout<<dp[m]<<endl;

    }

    return 0;
}