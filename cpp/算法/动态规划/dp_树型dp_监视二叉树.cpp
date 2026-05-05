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


    // 0: x是无覆盖的状态，x下方的节点都已经被覆盖
	// 1: x是覆盖状态，x上没摄像头，x下方的节点都已经被覆盖
	// 2: x是覆盖状态，x上有摄像头，x下方的节点都已经被覆盖
    int f(TreeNode *x)
    {
        if(x==nullptr) return 1;

        int left=f(x->left);
        int right=f(x->right);

        if(left==0||right==0)
        {
            ans++;
            return 2;
        }
        else if(left==1&&right==1) return 0;
        else return 1;
    }



    int minCameraCover(TreeNode *root) {
        ans=0;
        if(f(root)==0) ans++;

        return ans;
    }

    int ans;
};