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
    bool isSubtree(TreeNode* t1, TreeNode* t2)
    {
        if(t1!=nullptr&&t2!=nullptr)
        {
            vector<string> s1,s2;
            serial(t1,s1);
            serial(t2,s2);

            return kmp(s1,s2)!=-1;
        }

        return t2==nullptr;
    }

    void serial(TreeNode* t,vector<string>& s)
    {
        if(t==nullptr) s.push_back("null");
        else
        {
            s.push_back( to_string(t->val) );
            serial(t->left,s);
            serial(t->right,s);
        }
    }

    int kmp(vector<string> s1,vector<string> s2)
    {
        int n=s1.size(),m=s2.size();
        int x=0,y=0;
        vector<int> next_s2=get_next(s2,m);

        while(x<n&&y<m)
        {
            if(s_equal(s1[x],s2[y]))
            {
                x++; y++;
            }
            else if(y==0) x++;
            else y=next_s2[y];
        }

        return y==m? x-y : -1;
    }

    vector<int> get_next(vector<string> s,int siz)
    {
        if(siz==1) return {-1};

        vector<int> next(siz);
        next[0]=-1,next[1]=0;
        int i=2,cn=0;

        while(i<siz)
        {
            if(s_equal(s[i-1],s[cn]))
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

    bool s_equal(string a,string b)
    {
        if(a=="null"&&b=="null") return true;
        else if(a!="null"&&b!="null") return a==b;
        else return false;
    }
};