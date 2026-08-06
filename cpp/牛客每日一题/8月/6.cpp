#include<bits/stdc++.h>
using namespace std;



struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    using ll = long long;
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param tree TreeNode类 
     * @return int整型
     */
        ll getsum(TreeNode* tree)
        {
            if(tree)
            {
                return (1+max(getsum(tree->left),getsum(tree->right))*2);
            }
            return 0;
        }


    int getTreeSum(TreeNode* tree) {
        // write code here
        return getsum(tree)%1000000007;
    }
};