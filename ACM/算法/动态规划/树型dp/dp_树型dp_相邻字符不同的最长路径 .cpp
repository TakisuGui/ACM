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

    struct Info
    {
        int max_path_fromhead; //一定要从头节点出发的情况下,相邻字符不等的最长路径长度
        int maxpath;           //整棵树上.相邻字符不等的最长路径长度

        Info(int a,int b):max_path_fromhead(a),maxpath(b){}
    };

    Info dfs(const string& s,vector<vector<int>>& edges,int u)
    {
        if(edges[u].empty()) return{1,1};

        int max1=0; //下方最长链
        int max2=0; //下方次长链
        int maxpath=1;
        int max_path_fromhead=1;

        for(auto v:edges[u])
        {
            Info nextInfo=dfs(s,edges,v);
            maxpath=max(maxpath,nextInfo.maxpath);

            if(s[u]!=s[v])
            {
                if(nextInfo.max_path_fromhead>max1)
                {
                    max2=max1;
                    max1=nextInfo.max_path_fromhead;
                }
                else if(nextInfo.max_path_fromhead>max2)
                {
                    max2=nextInfo.max_path_fromhead;
                }
            }
        }

        max_path_fromhead=max1+1;
        maxpath=max(maxpath,max1+max2+1);

        return {max_path_fromhead,maxpath};
    }

    int longestPath(vector<int>& parent, string s)
    {
        int n=parent.size();
        vector<vector<int>> edges(n);

        for(int i=1;i<n;i++) edges[parent[i]].push_back(i);

        return dfs(s,edges,0).maxpath;
    }
};