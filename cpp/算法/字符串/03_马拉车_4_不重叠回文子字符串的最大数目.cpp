#include<bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    int n;
    int t;
    vector<int> p=vector<int>(4002,1);

    int maxPalindromes(string s, int k) 
    {
        int ans=0;
        int next_=0;
        n=s.size();
        t=n*2+1;
        string ss=get_ss(s,n);
        while((next_=find_(next_,k,ss))!=-1) ans++;

        return ans;
    }

    int find_(int l,int k,const string& ss)
    {
        for(int i=l,r=l,c=l,len;i<t;i++)
        {
            len=1;
            if(r>i) len=min(r-i,p[2*c-i]);
            while(i-len>=l&&i+len<t&&ss[i+len]==ss[i-len]) 
            {
                if(++len>k) return i+k+(ss[i+k]=='#' ? 0 :1);
            }

            if(i+len>r)
            {
                r=i+len;
                c=i;
            }
            p[i]=len;
        }
        return -1;
    }

    string get_ss(string s,int n)
    {
        string ss; ss.resize(2*n+1);

        for(int i=0,j=0;i<2*n+1;i++)
        {
            if(i%2==0) ss[i]='#';
            else ss[i]=s[j++];
        }
        return ss;
    }
};