#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e15+10;

vector<ll> f(101,0);

// 一共有n枚石子,两位玩家定了如下规则进行游戏：
// 先手后手轮流取石子,先手在第一轮可以取走任意的石子
// 接下来的每一轮当前的玩家最少要取走一个石子.最多取走上一次取的数量的2倍

void ini()
{
    f[0]=1;
    f[1]=2;
    for(int i=2;i<=100;i++) f[i]=f[i-1]+f[i-2];
}

// zeckendorf定理: 任何正整数 可以被分成 若干不连续的斐波那契数

void solve()
{
    ini();

    int n; cin>>n;

    if(binary_search(f.begin(),f.end(),n))
    {
        cout<<n<<endl;
        return;
    }

// 对于所有的斐波那契数
// 从1 2 考虑 发现如果不一次性取完必输
// 然后对于任何的斐波那契数发现,这个数可以被分解为上两项斐波那契数 a, b
// 一定有2*a>b 所以 一次性拿完a必输,所以只能分开判断俩个斐波那契数  (斐波那契数列增长比例趋近于黄金分割 1.618, 故恒成立)
// 递归考虑下去最后会轮到 3 ,而3由1, 2组成,所以如果一次性拿完3,必输
// 故而对于所有的斐波那契数必须一次性拿完

    ll temp=n;

    while(binary_search(f.begin(),f.end(),temp)==0)
    {
        auto i=lower_bound(f.begin(),f.end(),temp);
        int index=i-f.begin()-1;

        temp-=f[index];
    }

// 对于所有的非斐波那契数
// 其由若干斐波那契数组成,从小到大 a, b, c,...
// 先手拿去a个后,对于剩下的所有数,后手因为无法一次性拿完b,所以剩下所有的斐波那契数后手都是输家(先手总可以先拿完b,使得后手再次面对由 c, d,...仅由斐波那契数组成的数)
// 这样最后肯定只剩下一个斐波那契数,且这个时候轮到后手
// 由上面对一个斐波那契数若想取胜,只能把这个数一次性拿完
// 但后手有数量限制 并且因为这些斐波那契数一定不连续,一定有 f[i]>f[i-2]*2
// 所以后手肯定没办法一次性取完这个斐波那契数 也即后手必输

    cout<<temp<<endl;
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
