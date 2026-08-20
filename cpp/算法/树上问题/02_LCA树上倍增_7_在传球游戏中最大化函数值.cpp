#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100001;
const int M=2e5+10;
const int W=26;
const int LIM=34;
#define endl "\n"


class Solution {
public:

    int power;
    int m;

    vector<int> kbits=vector<int>(LIM);
    static int stjump[N][LIM];
    static ll stsum[N][LIM];

    void build(ll k)
    {
        power=0;
		while((1ll<<power)<=(k>>1)) power++;
		m=0;

        for(int p=power;p>=0;p--)
        {
            if((1ll<<p)<=k) 
            {
                kbits[m++]=p;
                k-=1LL<<p;
            }
        }
    }

    long long getMaxFunctionValue(vector<int>& receiver, long long k)
    {
        build(k);
        int n=receiver.size();

        for(int i=0;i<n;i++)
        {
            stjump[i][0]=receiver[i];
            stsum[i][0]=receiver[i];
        }

        for(int p=1;p<=power;p++)
        {
            for(int i=0;i<n;i++)
            {
                stjump[i][p]=stjump[stjump[i][p-1]][p-1];
                stsum[i][p]=stsum[i][p-1]+stsum[stjump[i][p-1]][p-1];
            }
        }

        ll sum,ans=0;
        for(int i=0;i<n;i++)
        {
            int cur=i; sum=i;
            for(int j=0;j<m;j++)
            {
                sum+=stsum[cur][kbits[j]];
                cur=stjump[cur][kbits[j]];
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};

int Solution::stjump[N][LIM];
ll Solution::stsum[N][LIM];