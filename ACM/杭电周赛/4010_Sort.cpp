#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=15;

void solve()
{
    int n,m; cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];

    for(int i=0;i<n;i++) sort(a[i].begin(),a[i].begin()+m);

    bool pass=true; int choose=a[n-1][m-1]; bool find=false;
    for(int i=n-2;i>=0;i--)
    {
        find=false;
        for(int j=m-1;j>=0;j--)
        {
            if(choose>a[i][j])
            {
                choose=a[i][j];
                find=true;
                break;
            }
        }

        if(find) continue;
        else
        {
            pass=false;
            break;
        }
    }

    if(pass) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}