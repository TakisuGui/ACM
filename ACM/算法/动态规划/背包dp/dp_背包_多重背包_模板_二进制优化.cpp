#include<bits/stdc++.h>
using namespace std;

int n,t;

int main()
{
    cin>>n>>t;
    vector<pair<int,int>> item;
    int pass=0;

    for(int i=1;i<=n;i++)
    {
        int x,m,v;
        cin>>x>>m>>v;

        for(int k=1;k<=x;k=k*2)
        {
            item.push_back({k*m,k*v});
            pass++;
            x=x-k;
        }
        if(x>0)
        {
            item.push_back({x*m,x*v});
            pass++;
        }
    }

    vector<int> dp(t+1,0);
    for(int i=0;i<pass;i++)
    {
        int vol=item[i].first;
        int val=item[i].second;

        for(int j=t;j>=0;j--)
        {
            if(j>=vol) dp[j]=max(dp[j],dp[j-vol]+val);
            else break;
        }
    }

    cout<<dp[t]<<endl;

    return 0;

}