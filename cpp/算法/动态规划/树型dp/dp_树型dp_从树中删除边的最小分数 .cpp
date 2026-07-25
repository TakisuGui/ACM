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


vector<int>dfn(1001);
vector<int> xors(1001); //子树异或和
vector<int>sz(1001);  //子树大小
int dfncnt=0;


class Solution {
public:
    

    void dfs(int u,vector<int>& nums,vector<vector<int>>& Edges)
    {
        int i=++dfncnt;
        dfn[u]=i;
        xors[i]=nums[u];
        sz[i]=1;

        for(auto v : Edges[u])
        {
            if(dfn[v]==0)
            {
                dfs(v,nums,Edges);
                xors[i]^=xors[dfn[v]];
                sz[i]+=sz[dfn[v]];
            }
        }
    }


    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) 
    {
        int n=nums.size();
        vector<vector<int>> Edges(n);
        for(auto& e : edges)
        {
            Edges[e[0]].push_back(e[1]);
            Edges[e[1]].push_back(e[0]);
        }

        fill(dfn.begin(),dfn.end(),0);
        dfncnt=0;

        dfs(0,nums,Edges);
        int m=edges.size();
        int ans=1e9;

        for(int i=0;i<m;i++)
        {
            int a=max(dfn[edges[i][0]],dfn[edges[i][1]]); //a是边i中深度更大的那个节点,因为此时下面的点本身作为头取异或值
            for(int j=i+1;j<m;j++)
            {
                int b=max(dfn[edges[j][0]],dfn[edges[j][1]]);

                int pos=max(a,b);
                int pre=min(a,b);

                int sum1,sum2,sum3;

                if(pos<pre+sz[pre]) //pos在pre的子树中
                {
                    sum1=xors[pos];
                    sum2=xors[pre]^xors[pos];
                    sum3=xors[1]^xors[pre];
                }
                else
                {
                    sum1=xors[pos];
                    sum2=xors[pre];
                    sum3=xors[1]^xors[pos]^xors[pre];
                }
                

                int mx=max({sum1,sum2,sum3});
                int mn=min({sum1,sum2,sum3});
                ans=min(ans,mx-mn);
            }
        }

        return ans;
    }
};