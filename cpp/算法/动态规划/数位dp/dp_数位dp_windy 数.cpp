#include<bits/stdc++.h>
using namespace std;
const int N=11;

int dp[N][N][2];

void build(int len) 
{
    for (int i = 0; i <= len; i++) 
    {
        for (int j = 0; j <= 10; j++) 
        {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
}

int f(int num, int offset, int len, int pre, int free);

int cnt(int num)
{
    if(num==0) return 1;

    int len=1;
    int offset=1;
    int tmp=num/10;

    while(tmp>0)
    {
        offset*=10;
        len++;
        tmp/=10;
    }

    build(len);

    return f(num,offset,len,10,0);
}

// 前一位的数字是pre，如果pre == 10，表示从来没有选择过数字
// 如果之前的位已经确定比num小，那么free == 1，表示接下的数字可以自由选择
// 如果之前的位和num一样，那么free == 0，表示接下的数字不能大于num当前位的数字
int f(int num,int offset,int len,int pre,int free)
{
    if(len==0) return 1;
    if(dp[len][pre][free]!=-1) return dp[len][pre][free];

    int cur=(num/offset)%10;
    int ans=0;

    if(free==0)
    {
        if(pre==10) //从来没有选择过数字,在最高位上
        {
            ans+=f(num,offset/10,len-1,10,1);

            for(int i=1;i<cur;i++)
            {
                ans+=f(num,offset/10,len-1,i,1);
            }

            //最高位等于cur时
            ans+=f(num,offset/10,len-1,cur,0);
        }
        else //之前选择了pre,且pre就是num这这一位上的数
        {
            for(int i=0;i<=9;i++)
            {
                if(i<=pre-2||i>=pre+2)
                {
                    if (i<cur) ans+=f(num,offset/10,len-1,i,1);
                    else if(cur==i) ans+=f(num,offset/10,len-1,cur,0);
                }
            }
        }
    }
    else
    {
        if(pre==10) //第一次选择数字,但是不在最高位
        {
            ans+=f(num,offset/10,len-1,10,1);
            
            for(int i=1;i<=9;i++)
            {
                ans+=f(num,offset/10,len-1,i,1);
            }
        }
        else //前面选择了小于那一位的数
        {
            for(int i=0;i<=9;i++)
            {
                if(i<=pre-2||i>=pre+2) ans+=f(num,offset/10,len-1,i,1);
            }
        }
    }

    dp[len][pre][free]=ans;
    return ans;
}


void solve()
{
    int a,b; cin>>a>>b;

    cout<<cnt(b)-cnt(a-1)<<endl;
}

int main()
{
    solve();

    return 0;
}
