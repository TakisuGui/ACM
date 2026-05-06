#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution {
public:
    void dfs(int u,int fa,vector<vector<int>>& edges,int seats,vector<int>& man,vector<long long>& cost)
    {
        man[u]=1;

        for(auto v:edges[u])
        {
            if(v==fa) continue;

            dfs(v,u,edges,seats,man,cost);
            man[u]+=man[v];
            cost[u]+=cost[v];
            cost[u]+=(man[v]+seats-1)/seats;
        }
    }


    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {

        int n=roads.size()+1;
        vector<vector<int>> edges(n);
        
        for(auto& road : roads)
        {
            int v=road[0],u=road[1];
            edges[v].push_back(u);
            edges[u].push_back(v);
        }

        vector<int> man(n,0);
        vector<long long> cost(n,0);

        dfs(0,-1,edges,seats,man,cost);

        return cost[0];
    }
};