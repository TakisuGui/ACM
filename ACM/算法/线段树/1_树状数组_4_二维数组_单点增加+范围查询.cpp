#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

class NumMatrix {
public:

    vector<vector<int>> tree;
    vector<vector<int>> num;
    int n,m;

    void NumMatrix_( vector<vector<int>>& matrix)
    {
        n=matrix.size();
        m=matrix[0].size();

        tree.assign(n,vector<int>(m));
        num.assign(n,vector<int>(m));

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                update(i,j,matrix[i][j]);
    }

    int lowbit(int i)
    {
        return i&(-i);
    }

    void add(int x,int y,int v)
    {
        for(int i=x;i<=n;i+=lowbit(i)) 
        {
            for(int j=y;j<=m;j+=lowbit(j))
            {
                tree[i][j]+=v;
            }
        }
    }

    // 从(1,1)到(x,y)这个部分的累加和
    int sum(int x,int y)
    {
        int ans=0;
        for(int i=x;i>0;i-=lowbit(i))
        {
            for(int j=y;j>0;j-=lowbit(j))
            {
                ans+=tree[i][j];
            }
        }
        return ans;
    }

    void update(int x,int y,int v)
    {
        add(x+1,y+1,v-num[x+1][y+1]);
        num[x+1][y+1]=v;
    }

    int range_sum(int a,int b,int c,int d)
    {
        return sum(c+1,d+1)-sum(a,d+1)-sum(c+1,b)+sum(a,b);
    }
};