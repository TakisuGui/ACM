#include<bits/stdc++.h>
using namespace std;


class Solution 
{
public:

    int max_,end_;

    string get_ss(string s)
    {
        string ss; ss.resize(s.size()*2+1);

        for(int i=0,j=0;i<ss.size();i++)
        {
            if(i%2==0) ss[i]='#';
            else ss[i]=s[j++];
        }
        return ss;
    }

    void get_p(string s,int n)
    {
        vector<int> p(n);
        max_=0,end_=0;

        for(int i=0,r=0,c=0,len;i<n;i++)
        {
            len=1;
            if(r>i) len=min(r-i,p[2*c-i]);
            while(i+len<n&&i-len>=0&&s[i-len]==s[i+len]) len++;

            if(i+len>r) r=i+len,c=i;
            if(max_<len)
            {
                max_=len;
                end_=(i+len-1)/2;
            }
            p[i]=len;
        }
        max_--;
    }

    string longestPalindrome(string s) 
    {
        int n=s.size();
        string ss=get_ss(s);
        get_p(ss,n*2+1);

        string ans;
        for(int i=end_-max_;i<end_;i++) ans.push_back(s[i]);
        return ans;
    }
};