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

    void f(TreeNode* x, int targetSum,long long sum,unordered_map<long long,int>& mpsum)
    {
        if(x==nullptr) return;

        sum+=x->val;
        ans+=mpsum[sum-targetSum];

        mpsum[sum]++;

        f(x->left,targetSum,sum,mpsum);
        f(x->right,targetSum,sum,mpsum);
        
        mpsum[sum]--;
    }


    int pathSum(TreeNode* root, int targetSum)
    {
        unordered_map<long long,int> mpsum;
        mpsum[0]=1;
        ans=0;
        f(root,targetSum,0,mpsum);

        return ans;
    }

    int ans;
};