#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;


// 有 n 堆石子
// 每人每次必须从任意一堆有 d 个石子的堆里取 1~d 个石子
// 取走最后一个石子输掉比赛

void solve()
{
    int n; cin>>n; int ans=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        ans^=x; sum+= (x==1 ? 1 : 0);
    }

    if(sum==n) cout<<(sum%2==1 ? "Brother" : "John")<<endl;
    else       cout<<(ans!=0 ? "John" : "Brother")<<endl;
}

// 对于全为1的情况,如果是奇数个后手赢,偶数个先手赢

// 对于其他的任何情况,一定可以转化为 只有一个堆数量 大于1 其他堆要么为零要么为一
// 这种转化后的情况是 异或和一定不为零 (因为比1位高的位数上必有数,在这个高位上存在1的时候,这个1有且只有一个)
// 假设现在大于1的堆数不唯一 
// 如果异或和不为零,操作后异或和必为零,那么一定至少有两个 大于1的堆
// 所有最后,一开始拿到异或和为零的的人,必然会把 只有一个堆数量 大于1 其他堆要么为零要么为一 这个情况交给对方使得对方必胜


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
