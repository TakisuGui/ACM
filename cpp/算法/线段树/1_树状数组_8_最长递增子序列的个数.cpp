#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=5e5+10;

class Solution {
public:

    int n,cnt;
    vector<int> temp=vector<int>(2005);
    vector<int> has=vector<int>(2005);
    vector<int> max_len=vector<int>(2005);
    vector<int> max_len_cnt=vector<int>(2005);

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
        int l=1,r=cnt,ans=n+1;
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
        temp=nums;

        sort(temp.begin()+1,temp.begin()+n+1);
        has[1]=temp[1];
        cnt=1;

        for(int i=2;i<=n;i++)
        {
            if(temp[i]!=temp[i-1]) has[++cnt]=temp[i];
        }

        int ans=0;
        for(int i=1;i<=n;i++) nums[i]=find_(nums[i]); 
        
        
    }
};