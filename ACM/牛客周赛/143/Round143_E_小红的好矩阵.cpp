#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll

void solve()
{
    int n; cin>>n;
    string s1,s2; cin>>s1>>s2;

    if(n%3!=0)
    {
        cout<<"-1"<<endl;
        return;
    }

    int m=n/3;

    int costA=0,costB=0,costC0=0,costC1=0;

    auto calc=[&](int l,string top,string bot)->int
    {
        int c=0;
        for(int k=0;k<3;k++)
        {
            if (s1[l+k]!=top[k]) c++;
            if (s2[l+k]!=bot[k]) c++;
        }

        return c;
    };

    for(int i=0;i<m;i++)
    {
        int l=i*3;

        int a1=calc(l,"001","011");
        int a2=calc(l,"011","001");

        int b1=calc(l,"100","110");
        int b2=calc(l,"110","100");

        int c1=calc(l,"000","111");
        int c2=calc(l,"111","000");

        costA+=min(a1,a2);
        costB+=min(b1,b2);

        if (i%2==0) costC0+=c1,costC1+=c2;
        else costC0+=c2,costC1+=c1;
    }

    cout<<min({costA,costB,costC0,costC1})<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}