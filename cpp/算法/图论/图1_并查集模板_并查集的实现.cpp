#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;

int fa[N];
int siz[N];
int stack_i[N];

void ini(int n)
{
    for(int i=0;i<=n;i++)
    {
        fa[i]=i;
        siz[i]=1;
    }
}

int find_(int i)
{
    int pass=0;
    while(i!=fa[i])
    {
        stack_i[pass]=i;
        pass++;
        i=fa[i];
    }
    while(pass>0)
    {
        pass--;
        fa[stack_i[pass]]=i;
    }

    return i;
}

bool is_same_(int a,int b)
{
    return find_(a)==find_(b);
}

void union_(int x,int y)
{
    int fx=find_(x),fy=find_(y);
    if(fx!=fy)
    {
        if(siz[fx]>=siz[fy])
        {
            siz[fx]+=siz[fy];
            fa[fy]=fx;
        }
        else
        {
            siz[fy]+=siz[fx];
            fa[fx]=fy;
        }
    }

}

void solve()
{
    int n,m; cin>>n>>m;

    ini(n);

    while(m--)
    {
        int op,a,b; cin>>op>>a>>b;

        if(op==1) cout<<(is_same_(a,b) ? "Yes" : "No")<<endl;

        else      union_(a,b);
    }

}

int main()
{
    solve();

    return 0;
}