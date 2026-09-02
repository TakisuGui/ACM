#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;
int n,m;
ll a[N];//每个水池的水量
int fa[N],L[N],R[N]; //并查集数组
ll sum[N]; //每个连通块的总水量
int cnt[N]; //每个连通块的水池个数

int find(int x)
{
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}

void merge(int x,int y)
{
    x=find(x); y=find(y);
    if(x==y) return;

    if(cnt[x]<cnt[y]) swap(x,y);

    fa[y]=x;
    sum[x]+=sum[y];
    cnt[x]+=cnt[y];
    L[x]=min(L[x],L[y]);
    R[x]=max(R[x],R[y]);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        fa[i]=i;
        sum[i]=a[i];
        cnt[i]=1;
        L[i]=R[i]=i;
    }

    cout<<fixed<<setprecision(10);

    while (m--)
    {
        int op; cin>>op;

        if(op==1)
        {
            int l,r; cin>>l>>r;

            while(find(l)!=find(r))
            {
                int next=R[find(l)]+1;
                merge(l, next);
            }

            int root=find(l);
            double avg=1.0*sum[root]/cnt[root];
        }
        else
        {
            int i; cin>>i;
            int root=find(i);
            double avg=1.0*sum[root]/cnt[root];
            cout<<avg<<'\n';
        }
    }
    
    return 0;
}