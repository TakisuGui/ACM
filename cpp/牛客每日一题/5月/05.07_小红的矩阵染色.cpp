#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6+10;

vector<int> cost(N);
bool found=false;
bool first=false;

int has=0;

void solve()
{
    int n,m,k; cin>>n>>m>>k; 
    vector<string> text(n);
    for(int i=0;i<n;i++) cin>>text[i];

    for(int j=0;j<m;j++)
    {
        found=false; //前面是不是一直有o
        first=true; //是否第一次 ? (2 : 1)
        for(int i=0;i<n;i++)
        {
            if(text[i][j]!='o') found=false,first=true;
            else
            {
                if(!found) found=true,first=true;
                else
                {
                    if(first)
                    {
                        cost[++has]+=2;
                        first=false;
                    }
                    else cost[has]+=1;
                }
            }
        }
    }

    sort(cost.begin()+1,cost.begin()+1+has);

    int t=has; int ans=0;

    while(k>0&&t>=1)
    {
        if(k-cost[t]>=0) ans+=cost[t]-1,k-=cost[t],t--;
        else 
        {
            ans+=k-1;
            break;
        }
    }

    cout<<ans<<endl;
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