#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int base=499;
const int MOD=1e7+7;

vector<ull> pow_(N,0);
vector<ull> hash_s1=vector<ull>(N,0);
vector<ull> hash_s2=vector<ull>(N,0);

void build(string s1,int n,string s2,int m)
{
    pow_[0]=1;
    for(int i=1;i<=n;i++) pow_[i]=pow_[i-1]*base;
    
    hash_s1[0]=s1[0]-'a'+1;
    for(int i=1;i<n;i++) hash_s1[i]=hash_s1[i-1]*base+s1[i]-'a'+1;
    hash_s2[0]=s2[0]-'a'+1;
    for(int i=1;i<m;i++) hash_s2[i]=hash_s2[i-1]*base+s2[i]-'a'+1;
}

ull get_hash(vector<ull>& hash,int l,int r)
{
    ull ans=hash[r];
    if(l>0) ans-=hash[l-1]*pow_[r-l+1];
    return ans;
}

bool is_same_(int l1,int l2,int len)
{
    return get_hash(hash_s1,l1,l1+len-1)==get_hash(hash_s2,l2,l2+len-1);
}

bool check(int l1,int r1,int k=3)
{
    int diff=0;
    int l2=0;
    while(l1<=r1&&diff<=k)
    {
        int l=1;
        int r=r1-l1+1;
        int len=0; int mid;

        while(l<=r)
        {
            mid=(l+r)/2;
            if(is_same_(l1,l2,mid))
            {
                len=mid;
                l=mid+1;
            }
            else r=mid-1;
        }

        if(l1+len<=r1) diff++;
        l1+=len+1;
        l2+=len+1;
    }
    return diff<=k;
}

void solve()
{
    string s1,s2; cin>>s1>>s2;
    int n=s1.size(),m=s2.size();

    if(n<m)
    {
        cout<<0<<endl;
        return;
    }

    build(s1,n,s2,m);
    int ans=0;
    for(int i=0;i<=n-m;i++)
    {
        if(check(i,i+m-1)) ans++;
    }
    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}