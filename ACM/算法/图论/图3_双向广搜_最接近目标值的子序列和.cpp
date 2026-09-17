#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    void dfs(int i,int e,long long s,vector<int>& nums,vector<long long>& res)
        {
            if(i==e)
            {
                res.push_back(s);
                return;
            }

            dfs(i+1,e,s,nums,res);
            dfs(i+1,e,s+nums[i],nums,res);
        }
    
    int minAbsDifference(vector<int>& nums, int goal) {

            int n=nums.size();
            vector<long long> rsum,lsum;

            dfs(0,n/2,0,nums,lsum);
            dfs(n/2,n,0,nums,rsum);

            sort(lsum.begin(),lsum.end());
            sort(rsum.begin(),rsum.end());

            long long min_ans=abs(goal);

            int i=0; int j=rsum.size()-1;

            while(i<lsum.size()&&j>=0)
            {
                long long cur=lsum[i]+rsum[j];
                long long diff=cur-goal;

                min_ans=min(min_ans,abs(diff));

                if(min_ans==0) return 0;

                if(cur>goal) j--;
                else i++;
            }

            return (int)min_ans;
    }
};