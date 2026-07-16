#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    map<ll,ll> trees;
    int q; cin>>q; ll total=0;
    while(q--)
    {
        ll type,h; cin>>type>>h;
        if(type==1)
        {
            trees[h]++;
            total++;
        }
        else
        {
            auto it_up=trees.upper_bound(h);

            for(auto it=trees.begin();it!=it_up;)
            {
                total-=(*it).second;
                it=trees.erase(it);
            }
        }
        cout<<total<<"\n";
    }
}