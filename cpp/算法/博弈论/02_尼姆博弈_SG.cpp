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
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    int mx=0;
    for(auto k : a) mx=max(mx,k); //找到堆中最大的 其为一次性最多可以拿取的数量

    // 分成一堆一个小游戏 
    // 对于每一个有 t 个石子的堆
    // 可以拿 1 ~ t 个
    vector<int> sg(mx+1);
    vector<bool> appear(mx+1,false);

    for(int i=1;i<=mx;i++) // 直接取最大的数量 这样一定可以把更小的堆数量的 sg 算出来
    {
        for(int j=0;j<i;j++) appear[i]=true; //即可以转移的前驱

        for(int k=0;k<=mx;k++)
        {
            if(!appear[k]) {sg[i]=k; break;}
        }
    }

    int ans=0;
    for(int num : a) ans^=sg[num];

    cout<< (ans!=0 ? "先手" : "后手")<<endl;;
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
