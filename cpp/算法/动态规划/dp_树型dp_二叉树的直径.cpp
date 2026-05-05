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
        int diameter;  // 当前子树中的最大直径
        int height;    // 当前子树的高度
        
        Info(int a,int b): diameter(a),height(b) {}
    };

    Info f(TreeNode* x)
    {
        if(x==nullptr) return Info(0,0);

        Info leftInfo=f(x->left);
        Info rightInfo=f(x->right);

        int height=max(leftInfo.height,rightInfo.height)+1;
        int diameter=max({leftInfo.height+rightInfo.height , leftInfo.diameter , rightInfo.diameter});

        return Info(diameter,height);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        return f(root).diameter;
    }

};