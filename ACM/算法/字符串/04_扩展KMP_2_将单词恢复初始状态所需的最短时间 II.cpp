#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector<int> get_Z(string s,int n)
    {
        vector<int> Z(n); Z[0]=n;

        for(int i=1,c=1,r=1;i<n;i++)
        {
            int len=0;
            if(r>i) len=min(r-i,Z[i-c]);
            while(i+len<n&&s[len]==s[len+i]) len++;

            if(i+len>r)
            {
                r=i+len;
                c=i;
            }
            Z[i]=len;
        }
        return Z;
    }

    int minimumTimeToInitialState(string word, int k) 
    {
        int n=word.size();
        vector<int> Z=get_Z(word,n);

        for(int i=k;i<n;i+=k)
        {
            if(Z[i]==n-i) return i/k;
        }

        return (n+k-1)/k;
    }
};