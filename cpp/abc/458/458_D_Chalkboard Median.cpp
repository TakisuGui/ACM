#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6+10;

priority_queue<int,vector<int>,greater<int>> heap_small;//小跟堆
priority_queue<int,vector<int>,less<int>> heap_big;//大跟堆

void solve()
{
    int x; cin>>x; heap_big.push(x);
    int q; cin>>q;
    while(q--)
    {
        int a,b; cin>>a>>b;
        
        if(a>heap_big.top()) heap_small.push(a);
        else heap_big.push(a);
        if(b>heap_big.top()) heap_small.push(b);
        else heap_big.push(b);

        while(heap_small.size()+1<heap_big.size())
        {
            heap_small.push(heap_big.top());
            heap_big.pop();
        }
        while(heap_small.size()>=heap_big.size())
        {
            heap_big.push(heap_small.top());
            heap_small.pop();
        }

        cout<<heap_big.top()<<endl;
    }
}


signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}