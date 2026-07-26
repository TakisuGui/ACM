#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    const int N=2e4+10;
    vector<int> fa=vector<int>(N);
    vector<int> siz=vector<int>(N);
    vector<int> factors=vector<int>(100010,-1);
    // factors[a] = b
	// a这个质数因子，最早被下标b的数字拥有

    void ini(int n){for(int i=0;i<n;i++) fa[i]=i,siz[i]=1;}

    int find_(int i)
    {
        if(i!=fa[i]) fa[i]=find_(fa[i]);
        return fa[i];
    }

    void union_(int x,int y)
    {
        int fx=find_(x),fy=find_(y);

        if(fx!=fy)
        {
            if(siz[fx]>=siz[fy])
            {
                fa[fy]=fx;
                siz[fx]+=siz[fy];
            }
            else
            {
                fa[fx]=fy;
                siz[fy]+=siz[fx];
            }
        }
    }

    int maxsiz(int n)
    {
        int maxs=-1;
        for(int i=0;i<n;i++) maxs=max(maxs,siz[i]);
        return maxs;
    }


    int largestComponentSize(vector<int>& nums) 
    {
        int n=nums.size();
        ini(n);

        for(int i=0;i<n;i++)
        {
            for(int j=2;j*j<=nums[i];j++)
            {
                if(nums[i]%j==0)
                {
                    if(factors[j]==-1) factors[j]=i;
                    else union_(factors[j],i);

                    while(nums[i]%j==0) nums[i]/=j;
                }
            }

            if(nums[i]>1)
            {
                if(factors[nums[i]]==-1) factors[nums[i]]=i;
                else union_(factors[nums[i]],i);
            }
        }

        return maxsiz(n);
    }
};