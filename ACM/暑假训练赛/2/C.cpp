#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=5e5+10;

int n,cnt;
vector<int> a(N);
vector<int> temp(N);
vector<int> tree1(N);
vector<int> tree2(N);
vector<int> has(N);

int lowbit(int x)
{
    return x&(-x);
}

void add(vector<int>& tree,int i,int v)
{
    while(i<=n)
    {
        tree[i]+=v;
        i+=lowbit(i);
    }
}

int sum(vector<int>& tree, int i)
{
    int ans=0;
    while(i>0)
    {
        ans+=tree[i];
        i-=lowbit(i);
    }
    return ans;
}

int find_(int v)
{
    int l=1,r=cnt,ans=cnt+1;
    while(l<=r)
    {
        int mid=(l+r)>>1;

        if(has[mid]>=v)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    temp=a;

    sort(temp.begin()+1,temp.begin()+n+1);
    has[1]=temp[1];
    cnt=1;

    for(int i=2;i<=n;i++)
    {
        if(temp[i]!=has[cnt]) has[++cnt]=temp[i];
    }

    int ans=0;
    for(int i=1;i<=n;i++) a[i]=find_(a[i]);

    for(int i=1;i<=n;i++)
    {
        ans+=sum(tree2,a[i]-1);
        add(tree1,a[i],1);
        add(tree2,a[i],sum(tree1,a[i]-1));
    }
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}