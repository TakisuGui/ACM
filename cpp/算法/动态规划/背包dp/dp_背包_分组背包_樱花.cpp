#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h1,m1,h2,m2,n;
    scanf("%d:%d",&h1,&m1);
    scanf("%d:%d",&h2,&m2);
    cin>>n;

    int time=(h2-h1)*60+(m2-m1);
    vector<int>dp(time+10,0);

     for(int i=1;i<=n;i++)
    {
        int c,t,p;
        cin>>t>>c>>p;

        if(p==0)
        {
            for(int j=0;j<=time;j++)
            {
                if(j-t>=0) dp[j]=max(dp[j],dp[j-t]+c);
            }
        }
        else
        {
            vector<pair<int,int>> item;
            int pass=0;
            int k;
            for(int k=1;k<=p;k=k*2)
            {
                item.push_back({k*t,k*c});
                pass++;
                p-=k;
            }
            if(p>=0)
            {
                item.push_back({p*t,p*c});
                pass++;
            }

            for(int q=0;q<pass;q++)
            {
                int T=item[q].first;
                int V=item[q].second;

                for(int j=time;j>=0;j--)
                {
                    if(j-T>=0) dp[j]=max(dp[j],dp[j-T]+V);
                }
            }
        }

    }

    cout<<dp[time]<<endl;

    return 0;

}