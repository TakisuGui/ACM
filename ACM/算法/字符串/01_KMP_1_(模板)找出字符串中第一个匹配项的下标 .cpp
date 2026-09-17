#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int strStr(string s1, string s2) 
    {
        return kmp(s1,s2);
    }

    int kmp(string s1,string s2)
    {
        int n=s1.size(),m=s2.size();
        int x=0,y=0; 
        // x s1中下标
        // y s2中下标

        vector<int> next_s2=get_next(s2,m);

        while(x<n&&y<m)
        {
            if(s1[x]==s2[y])
            {
                x++; y++;
            }
            else if(y==0) // 已经通过不断调用next_s2 使现在匹配于 s2 的开头 所有只能让 s1 后移
            {
                x++;
            }
            else y=next_s2[y];
        }

        return y==m ? x-y : -1;
    }

    vector<int> get_next(string s,int siz)
    {
        if(siz==1) return {-1};

        vector<int> next(siz);
        next[0]=-1,next[1]=0;

        int i=2,cn=0; 
        // i 当前要求next值的位置
		// cn 当前字符 要比对的前一个字符下标

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