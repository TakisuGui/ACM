#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;


void solve()
{
    int n; cin>>n;

    cout<<(n%6==0 ? "Roy wins!" : "October wins!")<<endl;
}


// 一个数 n 是必败态的条件是：
// 不能一次性把n直接取完
// 对于所有可取的正整数 d,n−d 都不是必败态 (全部可以取胜的数)

// 在本题中,必败态恰好是 6 的倍数,原因在于：
// 可取数 mod 6 只能是 {1,2,3,4,5} (即6以下对于先手都是必胜态),且不能一次性取6

// 一开始肯定有一堆(可能多也可能少的)数,这些数全部都是必胜态
// 第一个没办法一次性拿完的数就是必败态,
// 因为再往后的所有数不存在前面全是必胜的情况了

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