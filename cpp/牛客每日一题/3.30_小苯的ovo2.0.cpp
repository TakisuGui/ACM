#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int N=510;

int cal(string s)
{
    int dp2=0,dp0=0,dp1=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='o')
        {
            dp2+=dp1;
            dp0++;
        }
        else dp1+=dp0;
    }

    return dp2;
}


void solve()
{
    int dp[3];
    string text; cin>>text;
    dp[0]=dp[1]=dp[2]=0;

    vector<int> pos;
    for(int i=0;i<text.size();i++)
    {
        if(text[i]=='?')
        {
            pos.push_back(i);
            text[i]='o';
        }
    }
    int len=pos.size();
    int ans=cal(text);
    for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            text[pos[j]]='v';
            ans=max(ans,cal(text));
        }
        for(int j=i;j<len;j++) text[pos[j]]='o';
    }

    cout<<ans<<endl;
}


int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}