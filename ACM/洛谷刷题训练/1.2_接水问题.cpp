#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;

int main()
{
    cin>>n>>m;
    int ans=0;

    priority_queue<int,vector<int>,greater<int>> heap;

    for(int i=1;i<=m;i++) heap.push(0);

    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        auto out=heap.top();
        heap.pop();

        out+=x;
        heap.push(out);

        ans=max(ans,out);
    }

    cout<<ans<<endl;

    return 0;
}