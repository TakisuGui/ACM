#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int MOD=1e4+7;

int n;
unordered_map<ll,pair<int,int>> tp;
ll a[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            cout<<"NO"<<endl;
            return 0;
        }

        if(a[i]>0) tp[a[i]].first++;
        else tp[abs(a[i])].second++;
    }
  
    for(auto v:tp)
    {
        if(v.second.first>0&&v.second.second>0)
        {
            if(n-v.second.first-v.second.second==0)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    cout<<"YES"<<endl;

    return 0;
}