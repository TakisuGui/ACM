#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[110];
unordered_map<int,int> mp;

int main()
{
    int n,m; cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }

    cout<<(mp.size()==n ? "Yes" : "No")<<endl;

    int pass=true;
    for(int i=1;i<=m;i++)
    {
        if(mp[i]==0)
        {
            pass=false;
            break;
        }
    }
    cout<<(pass ? "Yes" : "No")<<endl;

    return 0;
}