#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int sum=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();

        for(auto v: nums) sum+=v;
        if(sum%k!=0) return false;

        vector<int> group(k,0);
        return f(group,sum/k,nums,n-1);    
    }

    bool f(vector<int>& group,int target,vector<int>& nums,int index)
    {
        if(index<0) return true;

        int num=nums[index];
        int len=group.size();

        for(int i=0;i<len;i++)
        {
            if(group[i]+num<=target)
            {
                group[i]+=num;

                if(f(group,target,nums,index-1)) return true;

                group[i]-=num;

                while(i+1<len&&group[i]==group[i+1]) i++;
            }
        }
        return false;
    }
};