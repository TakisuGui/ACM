#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;


// 有 n 堆石子
// 每人每次必须从任意一堆有 d 个石子的堆里取 1~d 个石子
// 最后没石子可取的人就输了

void solve()
{
    int n; cin>>n; int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        ans^=x;
    }

    cout<<(ans==0 ? "No" : "Yes")<<endl;
}


// 显然对于 全为 0 的 n 堆石子先手必输
// 那么可以推论 所有堆的石子数量全部异或起来 为零 ? 先手输 : 先手赢

// 如果现在异或值不为零, 一定有 任取一堆 将该堆数量m 与 异或和sum 相异或得到t,然后把该堆石子数量减少到t(如果石子不够就换一堆)
// 这样下一个接手的人,会面对异或和为零
// 如果异或和为零,一定有 无论怎么改变,异或和一定不为0
// 因为之前每一位上都有偶数个1 改变某一堆必然使该堆的数的二进制形式上的某一个1变成0,从而让这一位上的1的数量减少一个
// 最后必然使得异或和不为零

// 如此下去最后一定会有只有一堆有石子的情况(异或和不为零),这个情况必属于一开始拿到异或和不为零的人


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
