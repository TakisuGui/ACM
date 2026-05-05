#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;

int n;
int ne[N];
int du[N];
bool st[N];

int cnt;

void dfs(int x)
{
    cnt++;
    st[x]=true;

    int next=ne[x];
    if(!st[next]) dfs(next);
}


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ne[i];
        du[ne[i]]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++) if(du[i]==0) q.push(i);

    while(!q.empty())
    {
        auto a=q.front();q.pop();
        st[a]=true;

        int b=ne[a];
        du[b]--;
        if(du[b]==0) q.push(b);
    }

    int ans=n;
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            cnt=0;
            dfs(i);
            ans=min(ans,cnt);
        }
    }

    cout<<ans<<endl;

    return 0;
}