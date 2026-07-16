#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;

int under[N],above[N],move_i[N];

void solve()
{
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++) move_i[i]=0,under[i]=-1,above[i]=-1;

    for(int i=1;i<=q;i++)
    {
        int c,p; cin>>c>>p;

        int old_c_u=under[c];
        if(old_c_u!=-1) above[old_c_u]=-1;
        else move_i[c]=1;

        under[c]=p,above[p]=c;
    }

    for(int i=1;i<=n;i++)
    {
        int count=0;
        if(move_i[i]) count=0;

        else
        {
            int cur=i;
            while(cur!=-1)
            {
                count++;
                cur=above[cur];
            }
        }

        cout<<count<<" ";
    }
}



int main()
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