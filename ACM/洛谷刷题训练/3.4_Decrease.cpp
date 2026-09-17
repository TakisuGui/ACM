#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e3+10;

int n,m,k;

ll f[N][N];

void insert(int x1,int y1,int x2,int y2,int k)
{
    f[x1][y1]+=k;
    f[x1][y2+1]-=k;
    f[x2+1][y1]-=k;
    f[x2+1][y2+1]+=k;
}

int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;

        insert(x,y,x,y,z);
    }

    ll ans=0;

    for(int i=1;i<=n-k+1;i++)
    {
        for(int j=1;j<=n-k+1;j++)
        {
            ans+=abs(f[i][j]);
            int x2=i+k-1,y2=j+k-1;
            insert(i,j,x2,y2,-f[i][j]);
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!f[i][j])
            {
                cout<<"-1"<<endl;
                return 0;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}