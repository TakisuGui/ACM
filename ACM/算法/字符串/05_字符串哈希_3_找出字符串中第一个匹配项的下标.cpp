#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;


class Solution {
public:
    
    int N=1e5+10;
    int base=499;
    vector<ull> pow=vector<ull>(N,0);
    vector<ull> hash=vector<ull>(N,0);

    int strStr(string s1, string s2) 
    {
        int n=s1.size(),m=s2.size();
        build(s1,n);

        ull h2=s2[0]-'a'+1;
        for(int i=1;i<m;i++) h2=h2*base+s2[i]-'a'+1;

        for(int l=0,r=m-1;r<n;l++,r++)
        {
            if(ans(l,r)==h2) return l;
        }
        return -1;
    }

    void build(string s,int n)
    {
        pow[0]=1;
        for(int i=1;i<n;i++) pow[i]=pow[i-1]*base;

        hash[0]=s[0]-'a'+1;
        for(int i=1;i<n;i++) hash[i]=hash[i-1]*base+s[i]-'a'+1;
    }

    ull ans(int l,int r)
    {
        ull ans=hash[r];
        if(l>0) ans-=hash[l-1]*pow[r-l+1];
        return ans;
    }
};