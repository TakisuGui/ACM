#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

priority_queue<ll,vector<ll>,greater<ll>> heap;



int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll x;cin>>x;
        heap.push(x);
    }

    ll ans=0;
    while(heap.size()>1)
    {
        ll x=heap.top();heap.pop();
        ll y=heap.top();heap.pop();

        ans+=x+y;
        heap.push(x+y);
    }

    cout<<ans<<endl;

    return 0;
}