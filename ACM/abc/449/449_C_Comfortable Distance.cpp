#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,l,r;
string s;
vector<vector<int>>mp(26);
ll ans=0;

int main()
{
    cin>>n>>l>>r>>s;

    for(int i=0;i<n;i++)
    {
        int c=s[i]-'a';
        int low=i-r;
        int high=i-l;

        if(!mp[c].empty()&&low<=high)
        {
            auto l_it=lower_bound(mp[c].begin(),mp[c].end(),low);
            auto r_it=upper_bound(mp[c].begin(),mp[c].end(),high);
            ans+=(r_it-l_it);
        }

        mp[c].push_back(i);
    }

    cout<<ans<<endl;

    return 0;
}