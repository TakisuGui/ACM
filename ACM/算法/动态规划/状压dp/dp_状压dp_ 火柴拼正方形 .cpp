#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool makesquare(vector<int>& nums) 
    {
        int sum=0;
        for(auto v: nums) sum+=v;
        if(sum%4!=0) return false;

        int n=nums.size();
        vector<int> dp((1<<n),0);

        return f(nums,sum/4,(1<<n)-1,0,4,dp);
    }

    // limit:每条边规定的长度
	// status:表示哪些数字还可以选
	// cur:当前要解决的这条边已经形成的长度
	// rest:一共还有几条边没有解决
	// 返回:能否用光所有火柴去解决剩下的所有边
	// 因为调用子过程之前,一定保证每条边累加起来都不超过limit
    bool f(vector<int>& nums,int limit,int status,int cur,int rest,vector<int>& dp)
    {
        if(rest==0) return(status==0 ? true : false);
        if(dp[status]!=0) return (dp[status]==1 ? true : false);

        bool ans=false;
        for(int i=0;i<nums.size();i++)
        {
            if( (status&(1<<i)) && cur+nums[i]<=limit)
            {
                if(cur+nums[i]==limit) ans=f(nums,limit,status^(1<<i),0,rest-1,dp);
                else ans=f(nums,limit,status^(1<<i),cur+nums[i],rest,dp);
            }

            if(ans) break;
        }

        dp[status]=(ans ? 1 : -1);
        return ans;
    }
};