#include<bits/stdc++.h>
using namespace std;


// O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int> ends(n,0);

        int len=0; // len表示ends数组目前的有效区长度
        
        for(int i=0;i<n;i++)
        {
            int find_=bs1(ends,len,a[i]);

            if(find_==-1)
            {
                ends[len++]=a[i];
            }
            else ends[find_]=a[i];
        }

        return len;
    }

//  找到第一个 >=num的位置
    int bs1(vector<int>& ends,int len,int num)
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