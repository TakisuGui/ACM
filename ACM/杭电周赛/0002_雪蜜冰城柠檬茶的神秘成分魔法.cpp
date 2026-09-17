#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF=1e18;
const int MAXV=1e7+10;

struct Op {int type, x,y;};

int get_fate(unordered_map<int, int>& fate,int v)
{
    auto it=fate.find(v);
    if (it==fate.end()) return v;
    return it->second;
}

void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin>>a[i];

    int m;cin>>m;
    vector<Op> ops(m);

    for(int i=0;i<m;i++)
    {
        cin>>ops[i].type>>ops[i].x;
        if(ops[i].type == 1) cin>>ops[i].y;
    }

    unordered_map<int,int> fate;
    fate.reserve(200005);
    vector<int> append_res(m, -1);

    for (int i=m-1;i>=0;i--)
    {
        if (ops[i].type==2)
        {
            append_res[i]=get_fate(fate, ops[i].x);
        }
        else if (ops[i].type==1)
        {
            fate[ops[i].x]=get_fate(fate, ops[i].y);
        } 
        else if (ops[i].type==3) 
        {
            fate[ops[i].x]=-1;
        }
    }

    bool first = true;
    for (int i=0;i<n;i++)
    {
        int final_v=get_fate(fate, a[i]);
        if (final_v!=-1)
        {
            if (!first) cout << " ";
            cout << final_v;
            first=false;
        }
    }
    for (int i=0;i<m;i++)
    {
        if (append_res[i]!=-1)
        {
            if (!first) cout << " ";
            cout << append_res[i];
            first=false;
        }
    }
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if(cin>>t)
    {
        while(t--)
        {
            solve();
        }
    }
    return 0;
}