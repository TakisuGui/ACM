#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=3000001;

vector<vector<int>> tree=vector<vector<int>> (N,vector<int>(2,0));

class Solution 
{
public:
    
    int cnt=1;
    int high;

    void clear() 
    {
		for(int i=1;i<=cnt;i++) tree[i][0]=tree[i][1]=0;
	}

    void insert_(int x)
    {
        int cur=1;
        for(int i=high;i>=0;i--)
        {
            int j=(x>>i)&1;
            
            if(tree[cur][j]==0) tree[cur][j]=++cnt;

            cur=tree[cur][j];
        }
    }

    void build(vector<int>& nums)
    {
        int max_=0;
        for(auto x : nums) max_=max(max_,x);
        if(max_!=0) high=31-__builtin_clz(max_);
        else high=0;

        for(auto x : nums) insert_(x);
    }

    int maxxor(int x)
    {
        int cur=1; int ans=0;
        for(int i=high;i>=0;i--)
        {
            int j=(x>>i)&1;
            int want=j^1;

            if(tree[cur][want]==0) want^=1;

            ans|=(j^want)<<i;
            cur=tree[cur][want];
        }
        return ans;
    }

    int findMaximumXOR(vector<int>& nums)
    {
        build(nums);
        int ans=0;
        for(auto x : nums) ans=max(ans,maxxor(x));
        clear();
        return ans;
    }
};