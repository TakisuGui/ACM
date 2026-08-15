#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2001;

class Solution 
{
public:

    vector<int> a;
    vector<int> has=vector<int>(2001);

    vector<int> max_=vector<int>(4*N);
    vector<int> change=vector<int>(4*N);
    vector<bool> update=vector<bool>(4*N);

    void up(int i)
    {
        max_[i]=max(max_[i<<1],max_[i<<1|1]);
    }

    void lazy(int i,int v)
    {
        update[i]=true;
        change[i]=v;
        max_[i]=v;
    }

    void down(int i)
    {
        if(update[i])
        {
            lazy(i<<1,change[i]);
            lazy(i<<1|1,change[i]);
            update[i]=false;
        }
    }

    void build(int l,int r,int i)
    {
        if(l==r) max_[i]=0;
        else
        {
            int mid=(l+r)>>1;
            build(l,mid,i<<1);
            build(mid+1,r,i<<1|1);
            up(i);
        }
        update[i]=false;
        change[i]=0;
    }

    void update_(int jobl,int jobr,int v,int l,int r,int i)
    {
        if(jobl<=l&&r<=jobr) lazy(i,v);
        else
        {
            int mid=(l+r)>>1;
            down(i);

            if(jobl<=mid) update_(jobl,jobr,v,l,mid,i<<1);
            if(jobr>mid) update_(jobl,jobr,v,mid+1,r,i<<1|1);

            up(i);
        }
    }

    int query(int jobl,int jobr,int l,int r,int i)
    {
        if(jobl<=l&&r<=jobr) return max_[i];
        else
        {
            int mid=(l+r)>>1;
            down(i);
            int ans=-1e9;

            if(jobl<=mid) ans=max(ans,query(jobl,jobr,l,mid,i<<1));
            if(jobr>mid) ans=max(ans,query(jobl,jobr,mid+1,r,i<<1|1));

            return ans;
        }
    }

    int find_(int v,int cnt)
    {
        int l=1,r=cnt,ans=cnt+1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(has[mid]>=v)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }

    vector<int> fallingSquares(vector<vector<int>>& positions) 
    {
        for(auto& x : positions)
        {
            a.push_back(x[0]);
            a.push_back(x[0]+x[1]-1);
        }

        sort(a.begin(),a.end());
        int cnt=1;
        has[1]=a[0];
        
        for(int i=1;i<a.size();i++)
        {
            if(a[i]!=has[cnt]) has[++cnt]=a[i];
        }

        build(1,cnt,1);

        int max_h=-1e9;
        vector<int> ans;
        for(auto& x : positions)
        {
            int l=find_(x[0],cnt);
            int r=find_(x[1]+x[0]-1,cnt);
            int h=query(l,r,1,cnt,1)+x[1];
            max_h=max(max_h,h);
            ans.push_back(max_h);

            update_(l,r,h,1,cnt,1);
        }
        return ans;
    }
};