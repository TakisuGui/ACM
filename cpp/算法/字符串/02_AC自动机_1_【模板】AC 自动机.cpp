#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N=2e5+10;

vector<int> end_(N); // 记录每个目标串的结尾节点编号
vector<vector<int>> tree(N,vector<int>(26)); // 前缀树
vector<int> fail(N);
int cnt=0; // 节点数
vector<int> times(N); // 每个节点的词频
vector<int> Edges[N];


void insert_(int i,string t) // 每一个字符分配节点
{
    int u=0;
    for(int j=0;j<t.size();j++)
    {
        int c=t[j]-'a';
        if(tree[u][c]==0) tree[u][c]=++cnt;

        u=tree[u][c];
    }
    end_[i]=u;
}

void setfail()
{
    queue<int> q;
    for(int i=0;i<=25;i++)
    {
        if(tree[0][i]!=0) q.push(tree[0][i]);
    }

    while(!q.empty())
    {
        int u=q.front(); q.pop();
        for(int i=0;i<=25;i++)
        {
            if(tree[u][i]==0) tree[u][i]=tree[fail[u]][i];
            else 
            {
                fail[tree[u][i]]=tree[fail[u]][i];
                q.push(tree[u][i]);
            }
        }
    }
}

void f1(int u)
{
    for(auto v : Edges[u])
    {
        f1(v);
        times[u]+=times[v];
    }
}


int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        string t; cin>>t;
        insert_(i,t);
    }
    setfail();

    string s; cin>>s;
    for(int u=0,i=0;i<s.size();i++)
    {
        u=tree[u][s[i]-'a'];
        times[u]++;
    }


    for(int i=1;i<=cnt;i++)
    {
        Edges[fail[i]].push_back(i);
    }
    f1(0);

    for(int i=1;i<=n;i++) cout<<times[end_[i]]<<endl;

    return 0;
}