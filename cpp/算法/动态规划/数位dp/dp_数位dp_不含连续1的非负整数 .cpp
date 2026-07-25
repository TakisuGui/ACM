#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findIntegers(int n) {
        vector<int> cnt(32);
        cnt[0]=1;
        cnt[1]=2;
        for(int len=2;len<=30;len++) cnt[len]=cnt[len-1]+cnt[len-2];

        return f(cnt,n,30);
    }

    int f(vector<int>& cnt,int num,int i)
    {
        if(i==-1) return 1;

        int ans=0;
        if( ( num&(1<<i) ) !=0 )
        {
            ans+=cnt[i];
            if( ( num&(1<<(i+1)) ) !=0 ) return ans;
        }

        ans+=f(cnt,num,i-1);

        return ans;
    }
};