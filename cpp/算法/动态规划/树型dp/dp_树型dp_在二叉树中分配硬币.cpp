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
        int cnt;   // 子树中的节点个数
        int sum;   // 子树中的金币总数
        int move;  // 使子树中每个节点有1枚金币所需的最小移动次数
        
        Info(int a,int b,int c) : cnt(a),sum(b),move(c){}
    };

    Info f(TreeNode* x)
    {
        if(x==nullptr) return Info(0,0,0);

        Info leftInfo=f(x->left);
        Info rightInfo=f(x->right);

        int sum=leftInfo.sum+rightInfo.sum+x->val;
        int cnt=leftInfo.cnt+rightInfo.cnt+1;
        int move=leftInfo.move+rightInfo.move
                +abs(leftInfo.sum-leftInfo.cnt)
                +abs(rightInfo.sum-rightInfo.cnt);

        return Info(cnt,sum,move);
    }


    int distributeCoins(TreeNode* root) {
         return f(root).move;
    }
};