#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int M=2e5+10;
const int W=26;
#define endl "\n"


class Solution {
public:

    vector<pair<int,int>> edges[N];
    vector<int> fa=vector<int>(N);
    vector<pair<int,int>> has[N];
    vector<bool> vis=vector<bool>(N,false);
    vector<int> lca=vector<int>(M);
    vector<vector<int>> weight=vector<vector<int>>(N,vector<int>(W+1));

    void ini(int n) {for(int i=0;i<=n+1;i++) fa[i]=i;};

    int find_(int i)
    {
        if(i!=fa[i]) fa[i]=find_(fa[i]);

        return fa[i];
    }

    void dfs(int u,int w,int f)
    {
        if(u==0) fill(weight[u].begin(),weight[u].end(),0);
        else
        {
            for(int i=1;i<=W;i++) weight[u][i]=weight[f][i];
            weight[u][w]++;
        }

        for(auto& v : edges[u])
        {
            if(v.first!=f) dfs(v.first,v.second,u);
        }
    }

    void tarjan(int u,int f)
    {
        vis[u]=true;
        for(auto& v : edges[u])
        {
            if(v.first==f) continue;
            tarjan(v.first,u);
            fa[v.first]=u;
        }

        for(auto& [v,id] : has[u])
        {
            if(vis[v]) lca[id]=find_(v);
        }
    }


    vector<int> minOperationsQueries(int n, vector<vector<int>>& E, vector<vector<int>>& queries) 
    {
        ini(n);
        for(auto& e : E)
        {
            edges[e[0]].push_back({e[1],e[2]});
            edges[e[1]].push_back({e[0],e[2]});
        }
        dfs(0,0,-1);

        int m=queries.size();
        for(int i=0;i<m;i++)
        {
            has[queries[i][0]].push_back({queries[i][1],i});
            has[queries[i][1]].push_back({queries[i][0],i});
        }
        tarjan(0,-1);

        vector<int> ans(m);
        for(int i=0;i<m;i++)
        {
            int a=queries[i][0],b=queries[i][1],c=lca[i];
            int allcnt=0,maxcnt=0;

            for(int w=1;w<=W;w++)
            {
                int wcnt=weight[a][w]+weight[b][w]-2*weight[c][w];
                maxcnt=max(maxcnt,wcnt);
                allcnt+=wcnt;
            }
            ans[i]=allcnt-maxcnt;
        }
        return ans;
    }
};