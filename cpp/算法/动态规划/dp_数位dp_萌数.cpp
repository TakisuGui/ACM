#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e3+10;
const int MOD=1e9+7;

int dp[N][11][11][2];

void build(int n) {
		for (int a = 0; a < n; a++) {
			for (int b = 0; b <= 10; b++) {
				for (int c = 0; c <= 10; c++) {
					for (int d = 0; d <= 1; d++) {
						dp[a][b][c][d] = -1;
					}
				}
			}
		}
	}
int f(string num,int i,int pp,int p,int free);

int cnt(string num)
{
    if(num[0]=='0') return 0;

    int n=num.size();
    int all=0;
    int base=1;
    for(int i=n-1;i>=0;i--)
    {
        all=(all+base*(num[i]-'0'))%MOD;
        base=(base*10)%MOD;
    }
    build(n);

    return (all-f(num,0,10,10,0)+MOD)%MOD;
}

int f(string num,int i,int pp,int p,int free)
{
    if(i==num.size()) return 1;
    if(dp[i][pp][p][free]!=-1) return dp[i][pp][p][free];

    int ans=0;
    if(free==0)
    {
        if(p==10) //从来没有选择过数字,在最高位上
        {
            ans=(ans+f(num,i+1,p,10,1))%MOD;

            for(int cur=1;cur<num[i]-'0';cur++)
            {
                ans=(ans+f(num,i+1,p,cur,1))%MOD;
            }
            ans=(ans+f(num,i+1,p,num[i]-'0',0))%MOD;
        }
        else //之前选择的数和num完全相同
        {
            for(int cur=0;cur<num[i]-'0';cur++)
            {
                if(pp!=cur&&p!=cur) ans=(ans+f(num,i+1,p,cur,1))%MOD;
            }

            if(pp!=num[i]-'0'&&p!=num[i]-'0')
            {
                ans=(ans+f(num,i+1,p,num[i]-'0',0))%MOD;
            }
        }
    }
    else
    {
        if(p==10) //从来没有选择过数字,在不在最高位上
        {
            ans=(ans+f(num,i+1,p,10,1))%MOD;

            for(int cur=1;cur<=9;cur++)
            {
                ans=(ans+f(num,i+1,p,cur,1))%MOD;
            }
        }
        else //之前选择过数字,并且使得选择的数字组成的数已经小于num
        {
            for(int cur=0;cur<=9;cur++)
            {
                if(pp!=cur&&p!=cur) ans=(ans+f(num,i+1,p,cur,1))%MOD;
            }
        }
    }

    dp[i][pp][p][free]=ans;
    return ans;
}

bool check(string num)
{
    for(int pp=-2,p=-1,i=0;i<num.size();i++,p++,pp++)
    {
        if(pp>=0&&num[pp]==num[i]) return true;
        if(p>=0&&num[p]==num[i]) return true;
    }

    return false;
}

void solve()
{
    string l,r; cin>>l>>r;

    int ans=(cnt(r)-cnt(l)+MOD)%MOD;
    if(check(l)) ans=(ans+1)%MOD;

    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}