#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=150001;
const int MOD=998244353;

vector<vector<int>> tree(N,vector<int>(26,0));
vector<int> pass(N,0);
vector<int> end_(N,0);
int cnt=1;

void insert_(string s)
{
    int cur=1;
    pass[cur]++;

    for(int i=0;i<s.size();i++)
    {
        int j=s[i]-'a';
        if(tree[cur][j]==0)
        {
            tree[cur][j]=++cnt;
        }
        cur=tree[cur][j];
        pass[cur]++;
    }
    end_[cur]++;
}

int search_(int n,string s) // 前缀0 完整1
{
    int cur=1;
    for(int i=0;i<s.size();i++)
    {
        int j=s[i]-'a';
        if(tree[cur][j]==0) return 0;

        cur=tree[cur][j];
    }
    if(n==0)return pass[cur];
    else return end_[cur];
}

void delere_(string s)
{
    if(search_(1,s)>0)
    {
        int cur=1; pass[cur]--;
        for(int i=0;i<s.size();i++)
        {
            int j=s[i]-'a';
            if(--pass[tree[cur][j]]==0)
            {
                tree[cur][j]=0;
                return;
            }
            cur=tree[cur][j];
        }
        end_[cur]--;
    }
}

void solve()
{
    int n; cin>>n;
    while(n--)
    {
        int op; string s; cin>>op>>s;
        if(op==1) insert_(s);
        else if(op==2) delere_(s);
        else if(op==3) cout<<(search_(1,s)>0 ? "YES" : "NO")<<endl;
        else cout<<search_(0,s)<<endl;
    }
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