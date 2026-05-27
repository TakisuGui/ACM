#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;

int a[N][N];

int main()
{
    int n,m; cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }

    int ans=0;

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            int v1=a[i][j];
            int v2=a[i+1][j];
            int v3=a[i][j+1];
            int v4=a[i+1][j+1];

            if(v2!=v3&&v2!=v4&&v3!=v4&&v2+v3+v4==3) ans++;
            if(v1!=v3&&v1!=v4&&v3!=v4&&v1+v3+v4==3) ans++;
            if(v1!=v2&&v1!=v4&&v2!=v4&&v1+v2+v4==3) ans++;
            if(v1!=v2&&v1!=v3&&v2!=v3&&v1+v2+v3==3) ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}