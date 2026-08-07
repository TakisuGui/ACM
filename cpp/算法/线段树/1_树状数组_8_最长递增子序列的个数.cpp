#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int n,cnt;
    vector<int> temp=vector<int>(2005);
    vector<int> has=vector<int>(2005);
    vector<int> max_len=vector<int>(2005,0);
    vector<int> max_len_cnt=vector<int>(2005,0);

    int lowbit(int x)
    {
        return x&(-x);
    }


    // 以数值i结尾的最长递增子序列，长度达到了len，个数增加了cnt
    void add(int i,int len,int cnt)
    {
        while(i<=n)
        {
            if(max_len[i]==len) max_len_cnt[i]+=cnt;
            else if(max_len[i]<len)
            {
                max_len[i]=len;
                max_len_cnt[i]=cnt;
            }
            i+=lowbit(i);
        }
    }

    int maxLen,maxLenCnt;
    void query(int i)
    {
        maxLen=maxLenCnt=0;
        while(i>0)
        {
            if(max_len[i]==maxLen) maxLenCnt+=max_len_cnt[i];
            else if(max_len[i]>maxLen)
            {
                maxLen=max_len[i];
                maxLenCnt=max_len_cnt[i];
            }
            i-=lowbit(i);
        }
    }


    int find_(int v)
    {
        int l=0,r=cnt-1,ans=cnt;
        while(l<=r)
        {
            int mid=(l+r)/2;

            if(has[mid]>=v)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }


    int findNumberOfLIS(vector<int>& nums) 
    {
        n=nums.size();
        temp=nums;

        sort(temp.begin(),temp.begin()+n);
        has[0]=temp[0];
        cnt=1;

        for(int i=1;i<n;i++)
        {
            if(temp[i]!=temp[i-1]) has[cnt++]=temp[i];
        }

        int ans=0;
        for(int i=0;i<n;i++) nums[i]=find_(nums[i])+1; 
        
        for(auto& num : nums)
        {
            query(num-1);
            add(num,maxLen+1,max(maxLenCnt,1));
        }
        query(cnt);
        return maxLenCnt;
    }
};