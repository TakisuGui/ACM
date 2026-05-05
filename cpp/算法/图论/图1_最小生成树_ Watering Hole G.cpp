#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=8e4;

vector<pair <int, pair<int,int> > > edges(N);
int fa[N];

void ini(int n) {for(int i=1;i<=n+1;i++) fa[i]=i;};

int find_(int i)
{
    if(i!=fa[i]) fa[i]=find_(fa[i]);

    return fa[i];
}

bool union_(int x,int y)
{
    int fx=find_(x),fy=find_(y);

    if(fx!=fy)
    {
        fa[fx]=fy;
        return true;
    }
    else return false;
}

void solve()
{
    int n; cin>>n; //实际是n+1个节点
    ini(n);

    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        edges[i].first=x;
        edges[i].second.first=i;
        edges[i].second.second=n+1;
    }

    int edges_cnt=n+1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x; cin>>x;
            if(i==j||i>j) continue;

            edges[edges_cnt].first=x;
            edges[edges_cnt].second.first=i;
            edges[edges_cnt].second.second=j;

            edges_cnt++;
        }
    }

    sort(edges.begin()+1,edges.begin()+1+(n+1)*n/2);//实际上有(n+1)*n/2条边

    ll ans=0; int cnt=1;

    for(int i=1;i<=(n+1)*n/2;i++)
    {
        int dx=edges[i].second.first,dy=edges[i].second.second;
        int v =edges[i].first;

        if(union_(dx,dy))
        {
            cnt++;
            ans+=v;
        }
    }

    cout<<ans<<endl;
}



int main()
{
    solve();

    return 0;
}