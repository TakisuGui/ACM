#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int f(vector<int>& nums,int l,int r) 
    {
        if(l==r) return nums[l];

        else if(r==l+1) return max(nums[l],nums[r]);

        int p1=nums[l]+min(f(nums,l+2,r),f(nums,l+1,r-1));
        int p2=nums[r]+min(f(nums,l+1,r-1),f(nums,l,r-2));

        return max(p1,p2);
    }


    bool predictTheWinner(vector<int>& nums) {
        int sum=0;
        for(int num:nums) {sum+=num;}

        int n=nums.size();
        int first=f(nums,0,n-1);
        int second=sum-first;

        return first>=second;
    }
};