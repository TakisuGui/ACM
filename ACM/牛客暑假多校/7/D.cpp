#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=2e5+10;

int n,x;
vector<int> p(N);
vector<int> q(N);
vector<int> pos_p(N);
vector<int> pos_q(N);

vector<int> tree_p(N,0);
vector<int> tree_q(N,0);

vector<bool> vis_p(N,false);
vector<bool> vis_q(N,false);

vector<int> ans;

int lowbit(int i)
{
    return i&(-i);
}

void add(vector<int>& tree,int i,int v)
{
    while(i<=n)
    {
        tree[i]+=v;
        i+=lowbit(i);
    }
}

int sum(vector<int>& tree,int i)
{
    int ans=0;
    while(i>0)
    {
        ans+=tree[i];
        i-=lowbit(i);
    }
    return ans;
}

void solve()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++) 
    {
        cin>>p[i];
        pos_p[p[i]]=i;
    }
    for(int i=1;i<=n;i++) 
    {
        cin>>q[i];
        pos_q[q[i]]=i;
    }

    for(int i=1;i<=n;i++)
    {
        if(i==x) continue;

        if(pos_p[i]>pos_p[x]&&pos_q[i]>pos_q[x])
        {
            cout<<"NO"<<endl;
            return;
        }
    }


    for(int i=1;i<=n;i++)
    {
        add(tree_p,i,1);
        add(tree_q,i,1);
    }

    for(int i=1,j=1;i<=n&&j<=n&&ans.size()<n-1;)
    {
        while(vis_p[i]) i++;
        while(vis_q[j]) j++;

        if(p[i]==q[j])
        {
            cout<<"NO"<<endl;
            return;
        }

        if(p[i]==x)
        {
            add(tree_q,j,-1);
            add(tree_p,pos_p[q[j]],-1);
            ans.push_back(q[j]);

            vis_q[j]=true;
            vis_p[pos_p[q[j]]]=true;
        }
        else if(q[j]==x)
        {
            add(tree_p,i,-1);
            add(tree_q,pos_q[p[i]],-1);
            ans.push_back(p[i]);

            vis_p[i]=true;
            vis_q[pos_q[p[i]]]=true;
        }
        else
        {
            int a=sum(tree_q,pos_q[p[i]]); 
            int b=sum(tree_p,pos_p[q[j]]); 

            if(a>b)
            {
                add(tree_q,j,-1);
                add(tree_p,pos_p[q[j]],-1);
                ans.push_back(q[j]);

                vis_q[j]=true;
                vis_p[pos_p[q[j]]]=true;
            }
            else
            {
                add(tree_p,i,-1);
                add(tree_q,pos_q[p[i]],-1);
                ans.push_back(p[i]);

                vis_p[i]=true;
                vis_q[pos_q[p[i]]]=true;
            }
        }
    }

    cout<<"YES"<<endl;
    for(auto & v : ans) cout<<v<<" ";
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