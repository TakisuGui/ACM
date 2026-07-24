#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        vector<int> s2;
        ListNode* tmp=head;

        while(tmp!=NULL)
        {
            s2.push_back(tmp->val);
            tmp=tmp->next;
        }
        int m=s2.size();

        vector<int> next=get_next(s2,m);

        return find_(s2,next,root,0);
    }

    bool find_(const vector<int>&s2,const vector<int>& next,TreeNode* cur,int i)
    {
        if(i==s2.size()) return true;
        if(cur==NULL) return false;

        while(i>=0&&cur->val!=s2[i]) i=next[i];

        return find_(s2,next,cur->left,i+1)||find_(s2,next,cur->right,i+1);
    }

    vector<int> get_next(const vector<int>& s,int siz)
    {
        if(siz==1) return {-1};

        vector<int> next(siz);
        next[0]=-1,next[1]=0;

        int i=2,cn=0; 
        // i 当前要求next值的位置
		// cn 当前字符 要比对的前一个字符下标

        while(i<siz)
        {
            if(s[i-1]==s[cn])
            {
                next[i]=cn+1;
                cn++;
                i++;
            }
            else if(cn>0) cn=next[cn];
            else next[i]=0,i++;
        }

        return next;
    }
};