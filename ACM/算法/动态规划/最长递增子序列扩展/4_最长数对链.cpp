#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),[](const vector<int>& a,const vector<int>& b)
        {
            return a[0]<b[0];
        });

        vector<int> ends=vector<int>(n);
        int len=0;

        for(auto pair : pairs)
        {
            int find_=bs(ends,len,pair[0]);

            if(find_==-1) ends[len++]=pair[1];
            else ends[find_]=min(ends[find_],pair[1]); // 贪心
        }

        return len;
    }


    int bs(vector<int>& ends,int len,int num)
    {
        int l=0,r=len-1,ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;

            if(ends[mid]>=num)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};