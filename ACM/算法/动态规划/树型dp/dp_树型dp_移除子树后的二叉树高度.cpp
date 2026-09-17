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
    static const int MAXN = 100010;

    vector<int> dfn=vector<int>(MAXN);
    vector<int> deep=vector<int>(MAXN); //下标为dfn序号
    vector<int> size=vector<int>(MAXN); //DFS序中第i个节点的子树大小
    vector<int> maxl=vector<int>(MAXN);
    vector<int> maxr=vector<int>(MAXN);

    int dfnCnt=0;

    void dfs(TreeNode* x, int k) //从头节点到x节点经过了k条边
    {
        int i= ++dfnCnt;
        dfn[x->val]=i;
        deep[i]=k;
        size[i]=1;

        if(x->left!=nullptr)
        {
            dfs(x->left,k+1);
            size[i]+=size[dfn[x->left->val]];
        }
        if(x->right!=nullptr)
        {
            dfs(x->right,k+1);
            size[i]+=size[dfn[x->right->val]];
        }
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries)
    {
        dfnCnt=0;
        fill(dfn.begin(),dfn.end(),0);
        fill(deep.begin(),deep.end(),0);
        fill(size.begin(),size.end(),0);
        fill(maxl.begin(),maxl.end(),0);
        fill(maxr.begin(),maxr.end(),0);

        dfs(root, 0);

        for(int i=1;i<=dfnCnt;i++) maxl[i]=max(maxl[i-1],deep[i]);
        maxr[dfnCnt+1]=0;
        for(int i=dfnCnt;i>=1;i--) maxr[i]=max(maxr[i+1],deep[i]);

        int m=queries.size();
        vector<int> ans(m);

        for(int i=0;i<m;i++)
        {
            int pos=dfn[queries[i]];
            int leftMax=maxl[pos-1];
            int rightMax=maxr[pos+size[pos]];

            ans[i]=max(leftMax,rightMax);
        }

        return ans;
    }
};