#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    const int N=100001;
    vector<int> nums=vector<int>(N);
    vector<int> ends=vector<int>(N);

    int kIncreasing(vector<int>& arr, int k)
    {
        int n=arr.size();
        int ans=0;
        int size;

        for(int i=0;i<k;i++)
        {
            size=0;
            for(int j=i;j<n;j+=k) nums[size++]=arr[j];

            ans+=size-lengthOfLIS(size);
        }

        return ans;
    }

    int lengthOfLIS(int size) {

        int len=0;
        
        for(int i=0;i<size;i++)
        {
            int find_=bs1(len,nums[i]);

            if(find_==-1)
            {
                ends[len++]=nums[i];
            }
            else ends[find_]=nums[i];
        }

        return len;
    }

    int bs1(int len,int num)
    {
        int l=0,r=len-1,ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;

            if(ends[mid]>num)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }

        return ans;
    }
};