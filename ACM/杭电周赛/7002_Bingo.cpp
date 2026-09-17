#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=101;

int a[N][N];

void solve()
{
    int n; cin>>n;
    vector<set<int>> rowSet(n),colSet(n);
    set<int> allNums;  //所有出现过的数字
    
    for (int i=0; i<n;i++)
    {
        for (int j=0; j<n;j++)
        {
            cin>>a[i][j];
            rowSet[i].insert(a[i][j]);
            colSet[j].insert(a[i][j]);
            allNums.insert(a[i][j]);
        }
    }
    
    set<int> ans;
    for (int x:allNums)
    {
        bool ok=true;
        for (int i=0; i<n;i++) {
            if (!rowSet[i].count(x)) {
                ok=false;
                break;
            }
        }

        if(ok)
        {
            for(int j=0;j<n;j++) {
                if (!colSet[j].count(x)) {
                    ok=false;
                    break;
                }
            }
        }
        if(ok) ans.insert(x);
    }
    
    cout<<ans.size()<<endl;
    for (int v:ans) cout<<v<<" ";
    cout<<endl;
}


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