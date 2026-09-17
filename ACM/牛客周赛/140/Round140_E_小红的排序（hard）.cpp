#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

int fa[N];
int a[N];
int siz[N];

void ini(int n) {for(int i=1;i<=n;i++) fa[i]=i, siz[i]=1;};

int find_(int i)
{
    if(fa[i]!=i) fa[i]=find_(fa[i]);

    return fa[i];
}

void union_(int x,int y)
{
    int fx=find_(x),fy=find_(y);

    if(fx!=fy)
    {
        if(siz[fx]>=siz[fy])
        {
            fa[fy]=fx;
            siz[fx]+=siz[fy];
        }
        else
        {
            fa[fx]=fy;
            siz[fy]+=siz[fx];
        }
    }
}

void solve()
{
    int n,x,y; cin>>n>>x>>y;
    ini(n);

    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        int np=i+x,nq=i+y;

        if(np<=n) union_(i,np);
        if(nq<=n) union_(i,nq);
    }

    bool ok=true;

    for(int i=1;i<=n;i++)
    {
        if(find_(i)!=find_(a[i]))
        {
            ok=false;
            break;
        }
    }

    cout<<(ok ? "Yes" : "No")<<endl;
}


int main()
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