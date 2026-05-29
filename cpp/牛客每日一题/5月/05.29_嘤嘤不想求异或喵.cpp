#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e11+10;

int sum(int a)
{
    int p=a%4;
    if(p==0) return a;
    else if(p==1) return 1;
    else if(p==2) return a+1;
    else return 0;
}

void solve()
{
    int a,b; cin>>a>>b;

    cout<<(sum(a-1)^sum(b))<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}