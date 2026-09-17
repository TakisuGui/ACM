#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=3e5+10;
const int MOD=1e9+7;

void solve()
{
    int a,b,c,d; cin>>a>>b>>c>>d;
    string s; cin>>s;
    int n=s.size();

    int cnta=0,cntb=0;
    for(char ch : s)
    {
        if(ch=='A') cnta++;
        else cntb++;
    }
    
    if(cnta!=a+c+d||cntb!=b+c+d)
    {
        cout<<"NO"<<endl;
        return;
    }

    vector<int> ab_len,ba_len;
    int odd_pairs=0;

    for(int i=0;i<n;)
    {
        int j=i;
        while(j+1<n&&s[j]!=s[j+1]) j++;
        int len=j-i+1;

        if(len%2==0)
        {
            if(s[i]=='A') ab_len.push_back(len/2);
            else ba_len.push_back(len/2);
        }
        else odd_pairs+=len/2;

        i=j+1;
    }

    sort(ab_len.begin(),ab_len.end());
    sort(ba_len.begin(),ba_len.end());

    for(int k : ab_len)
    {
        if(k<=c) c-=k;
        else
        {
            int need_d=k-c-1;
            c=0;
            d-=need_d;
        }
    }
    for(int k : ba_len)
    {
        if(k<=d) d-=k;
        else
        {
            int need_c=k-d-1;
            d=0;
            c-=need_c;
        }
    }

    c=max(0LL,c);
    d=max(0LL,d);

    if (odd_pairs>= c+d) cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
    
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