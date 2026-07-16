#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;
int a[N];
int n;
unordered_map<int,int> cnt;
bool ans[N];
vector<int> edges[N];

void dfs(int u,int parent,bool has_pass)
{
    if(cnt[a[u]]>0) has_pass=true;
    cnt[a[u]]++;

    ans[u]=has_pass;

    for(auto v:edges[u])
    {
        if(v!=parent) dfs(v,u,has_pass);
    }

    cnt[a[u]]--;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n-1;i++)
    {
        int x,y; cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    dfs(1,-1,false);

    for(int i=1;i<=n;i++) cout<<(ans[i]?"Yes":"No")<<endl;

    return 0;
}