#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        if(n==0) return 1;

        int ans=10;

        for(int s=9,i=9,k=2;k<=n;i--,k++)
        {
            s*=i;
            ans+=s;
        }

        return ans;
    }
};