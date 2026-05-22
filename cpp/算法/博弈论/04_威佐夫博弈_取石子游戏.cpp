#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

long double e=(1.0l + sqrt(5.0l)) / 2.0l;

// 两堆石子
// 既可以在任意的一堆中取走任意多的石子
// 也可以在两堆中同时取走相同数量的石子
// 先把石子全部取完者为胜者
// 先手胜利为1,后手胜利为0

void solve()
{
    int a,b; cin>>a>>b;
    int big=max(a,b);
    int small=min(a,b);

    cout<<( small!=floorl( (long double)(big-small)*e+ 1e-9 ) ? 1 : 0)<<endl;
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
