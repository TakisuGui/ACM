#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int m,q;
unordered_map<int,int> mp;

int main()
{
    cin>>m>>q;
    int op;
    int x;
    int ans=0;

    while(q--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>x;
            if(x-3>=1)
            {
                mp[x-3]++;
                if(mp[x-3]==1) ans++;
            }
            if(x+3<=m)
            {
                mp[x+3]++;
                if(mp[x+3]==1) ans++;
            }
        }
        else
        {
            cin>>x;
            if(x-3>=1)
            {
                mp[x-3]--;
                if(mp[x-3]==0) ans--;
            }
            if(x+3<=m)
            {
                mp[x+3]--;
                if(mp[x+3]==0) ans--;
            }
        }



        cout<<ans<<endl;
    }

    return 0;
}