#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int N=2001;
    vector<vector<int>> pos=vector<vector<int>>(26);
    vector<int> tree=vector<int>(N,0);

    vector<int> a=vector<int>(N);
    vector<int> temp=vector<int>(N);
    
    int lowbit(int i)
    {
        return i&(-i);
    }

    void add(int i,int v,int n)
    {
        while(i<=n)
        {
            tree[i]+=v;
            i+=lowbit(i);
        }
    }

    int sum(int i)
    {
        int ans=0;
        while(i>0)
        {
            ans+=tree[i];
            i-=lowbit(i);
        }
        return ans;
    }

    int f(int l,int r)
    {
        if(l==r) return 0;

        int mid=(l+r)/2;
        int ans=f(l,mid)+f(mid+1,r);

        for(int i=mid,j=r;i>=l;i--)
        {
            while(a[j]>=a[i]&&j>=mid+1) j--;
            ans+=(j-mid);
        }

        int cnt=l,i=l,j=mid+1;
        while(i<=mid&&j<=r)
        {
            if(a[j]>=a[i])
            {
                temp[cnt++]=a[i];
                i++;
            }
            else
            {
                temp[cnt++]=a[j];
                j++;
            }
        }
        while(i<=mid) temp[cnt++]=a[i++];
        while(j<=r) temp[cnt++]=a[j++];

        for(int t=l;t<=r;t++) a[t]=temp[t];

        return ans;
    }

    int minMovesToMakePalindrome(string s) 
    {
        int n=s.size();
        
        for(int i=1;i<=n;i++) add(i,1,n);
        for(int i=0;i<n;i++) pos[s[i]-'a'].push_back(i+1);

        for(int i=0,l=1;i<n;i++,l++)
        {
            if(a[l]!=0) continue;

            int ch=s[i]-'a';
            int r=pos[ch].back(); pos[ch].pop_back();

            if(l<r)
            {
                int k=sum(l);
                a[l]=k; a[r]=n-k+1;
            }
            else a[l]=(1+n)/2;

            add(r,-1,n);
        }

        return f(1,n);
    }
};