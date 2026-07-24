#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    const int MOD=1e9+7;

    vector<vector<vector<int>>> dp{501,vector<vector<int>>(51,vector<int>(2,-1))};
    vector<int> next;

    void clear(int n, int m) 
    {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dp[i][j][0] = -1;
				dp[i][j][1] = -1;
			}
		}
	}

    int findGoodStrings(int n, string s1, string s2, string e) 
    {
        int m=e.size();
        next=get_next(e,m);
        clear(n,m);

        int ans=f(s2,e,n,m,0,0,0);
        clear(n,m);
        ans=(ans-f(s1,e,n,m,0,0,0)+MOD)%MOD;

        if(kmp(s1,e)==-1) ans=(ans+1)%MOD;

        return ans;
    }

    int f(const string& s,const string& e,int n,int m,int i,int j,int free)
    {
        if(j==m) return 0;
        if(i==n) return 1;
        if(dp[i][j][free]!=-1) return dp[i][j][free];

        char cur=s[i];
        int ans=0;
        if(free==0)
        {
            for(char pick='a';pick<cur;pick++)
            {
                ans=(ans+f(s,e,n,m,i+1,jump(pick,e,j)+1,1))%MOD;
            }
            ans=(ans+f(s,e,n,m,i+1,jump(cur,e,j)+1,0))%MOD;
        }
        else
        {
            for(char pick='a';pick<='z';pick++)
            {
                ans=(ans+f(s,e,n,m,i+1,jump(pick,e,j)+1,1))%MOD;
            }
        }

        dp[i][j][free]=ans;
        return ans;
    }

    int jump(char pick,const string& e,int j)
    {
        while(j>=0&&pick!=e[j]) j=next[j];

        return j;
    }

    int kmp(string s1,string s2)
    {
        int n=s1.size(),m=s2.size();
        int x=0,y=0; 
        // x s1中下标
        // y s2中下标

        while(x<n&&y<m)
        {
            if(s1[x]==s2[y])
            {
                x++; y++;
            }
            else if(y==0)
            {
                x++;
            }
            else y=next[y];
        }

        return y==m ? x-y : -1;
    }

    vector<int> get_next(string s,int siz)
    {
        if(siz==1) return {-1};

        vector<int> next(siz);
        next[0]=-1,next[1]=0;

        int i=2,cn=0; 

        while(i<siz)
        {
            if(s[i-1]==s[cn])
            {
                next[i]=cn+1;
                cn++;
                i++;
            }
            else if(cn>0) cn=next[cn];
            else next[i]=0,i++;
        }

        return next;
    }
};