#include<bits/stdc++.h>
using namespace std;

using ull=unsigned long long;

class Solution 
{
public:

    int v(int c) 
    {
        return c-'0'+1;
    }

    int equalDigitFrequency(string s)
    {
        int base=499;
        int n=s.size();

        set<ull> mp;
        

        for(int i=0;i<n;i++)
        {
            vector<int> cnt(10,0);
            ull ans=0,maxcnt=0,maxcntkinds=0,allkinds=0;
            for(int j=i;j<n;j++)
            {
                int cur=s[j]-'0';
                ans=ans*base+v(cur);
                cnt[cur]++;

                if(cnt[cur]==1) allkinds++;\

                if(cnt[cur]>maxcnt)
                {
                    maxcnt=cnt[cur];
                    maxcntkinds=1;
                }
                else if(cnt[cur]==maxcnt) maxcntkinds++;

                if(maxcntkinds==allkinds) mp.insert(ans);
            }
        }
        return mp.size();
    }
};