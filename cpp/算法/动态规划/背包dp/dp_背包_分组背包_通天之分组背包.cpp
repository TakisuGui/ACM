#include<bits/stdc++.h>
using namespace std;

int m,n;

int main()
{
    cin>>m>>n;
    vector<vector<pair<int,int>>> group;
    int maxg=0;
    vector<tuple<int,int,int>> items;

    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        items.push_back({a,b,c});
        maxg=max(maxg,c);
    }
    group.resize(maxg+1);
    for(auto&[a,b,c]:items) group[c].push_back({a,b});

    vector<int> dp(m+1,0);

    for(int g=1;g<=maxg;g++)
    {
        for(int j=m;j>=0;j--)
        {
            for(auto& [weight,value]:group[g])
            {
                if(j>=weight)
                dp[j]=max(dp[j],dp[j-weight]+value);
            }
        }
    }

    cout<<dp[m]<<endl;

    return 0;
}