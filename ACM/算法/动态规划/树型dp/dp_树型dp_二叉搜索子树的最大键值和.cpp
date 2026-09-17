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
        int maxVal;
        int minVal;
        int sum;
        bool isBst;
        int maxBstSum;

        Info(int a,int b,int c,bool d,int e) : maxVal(a), minVal(b),sum(c),isBst(d),maxBstSum(e) {}
    };

    Info f(TreeNode *x)
    {
        if (x==nullptr) return Info(INT_MIN,INT_MAX,0,true,0);

        Info leftInfo=f(x->left);
        Info rightInfo=f(x->right);

        int maxval=max({x->val,leftInfo.maxVal,rightInfo.maxVal});
        int minval=min({x->val,leftInfo.minVal,rightInfo.minVal});
        int sum=leftInfo.sum+rightInfo.sum+x->val;
        bool isBst=(leftInfo.isBst&&rightInfo.isBst) && (leftInfo.maxVal<x->val && x->val<rightInfo.minVal);

        int maxBstSum=max(leftInfo.maxBstSum,rightInfo.maxBstSum);
        if(isBst) maxBstSum=max(maxBstSum,sum);

        return Info(maxval,minval,sum,isBst,maxBstSum);
    }



    int maxSumBST(TreeNode* root)
    {
        return f(root).maxBstSum;
    }

};