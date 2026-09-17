#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e9+7;

int get_mex(int x,int y,int z)
{
    if (x!=0&&y!=0&&z!=0) return 0;
    if (x!=1&&y!=1&&z!=1) return 1;
    if (x!=2&&y!=2&&z!=2) return 2;
    return 3;
}

vector<int> tran(vector<int>& a,int n)
{
    vector<int> b(n);
    for(int i=0;i<n;i++)
    {
        int left=a[(i-1+n)%n];
        int mid=a[i];
        int right=a[(i+1+n)%n];
        b[i]=get_mex(left,mid,right);
    }
    return b;
}


void solve()
{
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int t;
    if(k<=4) t=k;
    else t = (k%2==0) ? 4 : 3;

    for(int i=0;i<t;i++) a=tran(a,n);
    
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
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
