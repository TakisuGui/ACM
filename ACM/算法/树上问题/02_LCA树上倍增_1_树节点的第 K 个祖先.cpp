#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+10;
const int LIM=16;


class TreeAncestor
{
public:
    vector<int> edges[N];
    vector<int> deep=vector<int>(N);
    vector<vector<int>> st=vector<vector<int>>(N,vector<int>(LIM));
    int power;

    TreeAncestor(int n, vector<int>& parent)
    {
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1) continue;
            edges[parent[i]].push_back(i);
        }
        power=log2(n);
        dfs(0,0);
    }
    
    int log2(int i)
    {
        int ans=0;
        while((1<<ans)<=(i>>1)) ans++;
        return ans;
    }

    void dfs(int i,int f)
    {
        if(i==0) deep[i]=1;
        else deep[i]=deep[f]+1;

        st[i][0]=f;
        for(int p=1;p<=power;p++)
        {
            st[i][p]=st[st[i][p-1]][p-1];
        }

        for(auto& v : edges[i])
        {
            dfs(v,i);
        }
    }

    int getKthAncestor(int i, int k) 
    {
        if(deep[i]<=k) return -1;

        int goal=deep[i]-k;
        for(int p=power;p>=0;p--)
        {
            if(deep[st[i][p]]>=goal) i=st[i][p];
        }
        return i;
    }
};