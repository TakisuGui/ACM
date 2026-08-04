#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
const int N=3e4+10;
const int base=499;


class Solution {
public:
    
    vector<ull> pow=vector<ull>(N,0);
    vector<ull> hash=vector<ull>(N,0);
    
    int repeatedStringMatch(string a, string b) 
    {
        int n=a.size(),m=b.size();
        int k=(n+m-1)/n+1;

        string s;
        for(int i=1;i<=k;i++) s+=a;
        int t=s.size();
        build(s,t);

        ull h2=b[0]-'a'+1;
        for(int i=1;i<m;i++) h2=h2*base+b[i]-'a'+1;

        for(int i=0,j=m-1;j<t;i++,j++)
        {
            if(ans(i,j)==h2) return j<(k-1)*n ? k-1 : k;  
        }
        return -1;
    }

    void build(string s,int n)
    {
        pow[0]=1;
        for(int i=1;i<=n;i++) pow[i]=pow[i-1]*base;
        
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