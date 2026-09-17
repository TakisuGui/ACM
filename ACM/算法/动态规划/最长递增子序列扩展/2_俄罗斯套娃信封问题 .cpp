#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n=envelopes.size();

        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a,const vector<int>& b)
        {
            if(a[0]==b[0]) return a[1]>b[1];
            else return a[0]<b[0];
        });

        vector<int> ends(n,0);
        int len=0;

        for(int i=0;i<n;i++)
        {
            int find_=bs1(ends,len,envelopes[i][1]);

            if(find_==-1)
            {
                ends[len++]=envelopes[i][1];
            }
            else ends[find_]=envelopes[i][1];
        }

        return len;
    }


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