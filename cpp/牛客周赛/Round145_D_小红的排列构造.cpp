#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{   
    int n; cin>>n;
    vector<int> a(n);
    vector<int> cnt(n+1,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }

    for(int i=1;i<=n;i++)
    {
        if(cnt[i]>2) {cout<<-1<<endl; return;}
    }

    vector<int> b(n,-1),c(n,-1);
    vector<bool> usedB(n+1,false),usedC(n+1,false);
    vector<int> firstPos(n+1,-1);

    for(int i=0;i<n;i++)
    {
        int x=a[i];
        if(cnt[x]==1)
        {
            b[i]=x,c[i]=x;
            usedB[x]=true;
            usedC[x]=true;
        }
        else if(cnt[x]==2)
        {
            if(firstPos[x]==-1)
            {
                firstPos[x]=i;
                b[i]=x;
                usedB[x]=true;
            }
            else
            {
                c[i]=x;
                usedC[x]=true;
            }
        }
    }

    vector<int> missing;
    for (int v=1;v<=n;v++) 
    {
        if (cnt[v]==0) missing.push_back(v);
    }

    int idx=0;
    for(int i=0;i<n;i++)
    {
        if(b[i]==-1)
        {
            b[i]=missing[idx++];
            usedB[b[i]]=true;
        }
    }
    idx=0;
    for(int i=0;i<n;i++) 
    {
        if (c[i]==-1) 
        {
            c[i]=missing[idx++];
            usedC[c[i]]=true;
        }
    }

    for (int i=0;i<n;i++) cout<<b[i]<<" ";
    cout<<endl;
    for (int i=0;i<n;i++) cout<<c[i]<<" ";
    cout<<endl;
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