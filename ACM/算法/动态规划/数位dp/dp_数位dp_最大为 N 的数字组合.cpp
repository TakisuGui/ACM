#include<bits/stdc++.h>
using namespace std;


class Solution1 {
public:
    int atMostNGivenDigitSet(vector<string>& strs, int num) 
    {
        int tmp=num/10;
        int len=1;
        int offset=1;
        while(tmp>0)
        {
            tmp/=10;
            len++;
            offset*=10;
        }

        int m=strs.size();
        vector<int> digits(m);
        for(int i=0;i<m;i++) digits[i]=strs[i][0]-'0';

        return f(digits,num,offset,len,0,0);
    }

    // 还剩下len位没有决定
    // 如果之前的位已经确定比num小,那么free == 1,表示接下的数字可以自由选择
	// 如果之前的位和num一样,那么free == 0,表示接下的数字不能大于num当前位的数字
	// 之前的位已经使用过数字 ? fix == 1 : 0 
    int f(vector<int>& digits,int num,int offset,int len,int free,int fix)
    {
        if(len==0) return fix==1 ? 1 : 0;

        int ans=0;
        int cur=(num/offset)%10;

        if(fix==0)
        {
            ans=f(digits,num,offset/10,len-1,1,0);
        }

        if(free==0)
        {
            for(int i : digits)
            {
                if(i<cur) ans+=f(digits,num,offset/10,len-1,1,1);
                else if(i==cur) ans+=f(digits,num,offset/10,len-1,0,1);
                else break;
            }
        }
        else ans+=digits.size()*f(digits,num,offset/10,len-1,1,1);

        return ans;
    }
};


class Solution2 {
public:
    int atMostNGivenDigitSet(vector<string>& strs, int num) 
    {
        int tmp=num/10;
        int len=1;
        int offset=1;
        while(tmp>0)
        {
            tmp/=10;
            len++;
            offset*=10;
        }

        int m=strs.size();
        vector<int> digits(m);
        for(int i=0;i<m;i++) digits[i]=strs[i][0]-'0';

        vector<int> cnt(len); cnt[0]=1; int ans=0;
        for(int i=m,k=1;k<len;k++,i*=m)
        {
            cnt[k]=i;
            ans+=i;
        }

        return  ans+f(digits,cnt,num,offset,len);
    }

    // 还剩下len位没有决定
    // 如果之前的位已经确定比num小,那么free == 1,表示接下的数字可以自由选择
	// 如果之前的位和num一样,那么free == 0,表示接下的数字不能大于num当前位的数字
	// 之前的位已经使用过数字 ? fix == 1 : 0 
    int f(vector<int>& digits,vector<int>& cnt,int num,int offset,int len)
    {
        if(len==0) return 1; //num自己

        int cur=(num/offset)%10;
        int ans=0;

        for(int i : digits)
        {
            if(i<cur) ans+=cnt[len-1];
            else if(i==cur) ans+=f(digits,cnt,num,offset/10,len-1);
            else break;
        }

        return ans;
    }
};