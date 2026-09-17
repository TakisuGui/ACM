#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e15+10;

// 三堆石头拿取斐波那契数博弈

vector<ll> f(101,0);
int a,b,c;

void ini()
{
    f[0]=1;
    f[1]=2;
    for(int i=2;i<=100;i++) f[i]=f[i-1]+f[i-2];
}

void solve()
{
    ini();
    cin>>a>>b>>c;
    int MAX=max({a,b,c});
    vector<int> sg(MAX+1);
    vector<int> appera(MAX+1,false);

    sg[0]=0;
    for(int i=1;i<=MAX;i++)
    {
        for(int j=0;j<f.size()&&i-f[j]>=0;j++)
        {
            appera[sg[i-f[j]]]=true;
        }

        for(int k=0;k<MAX;k++)
        {
            if(!appera[k])
            {
                sg[i]=k;
                break;
            }
        }
    }

    int ans=(sg[a]^sg[b]^sg[c]);

    cout<<(ans==0 ? "先手" : "后手")<<endl;
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


