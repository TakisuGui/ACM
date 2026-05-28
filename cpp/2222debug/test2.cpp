#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e3+10;

//打表找规律
int dp[N][N];

void ini()
{
    for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) 
			dp[i][j]=-1;
}

int sg(int a,int b)
{
    if(a==1&&b==1) return 0;
    if(dp[a][b]!=-1) return dp[a][b];

    vector<bool> appera(N+2,false);

    if(a>1)
    {
        for(int i=1;i<=a-1;i++) appera[sg(i,a-i)]=true;
    }
    if(b>1)
    {
        for(int i=1;i<=b-1;i++) appera[sg(i,b-i)]=true;
    }

    int ans=0;
    for(int k=0;k<=max(a,b);k++)
    {
        if(!appera[k]){ans=k; break;}
    }

    dp[a][b]=ans;
    return ans;
}

void test()
{
    ini();
    int k=0;
    for(int m=1;m<N;m++)
    {
        for(int n=m;n<N;n++) 
        {
            cout<<sg(m,n)<<" ";

            if(k==9)
            {
                cout<<endl;
                k=0;
            }
            else k++;
        }
    }
}


void solve()
{
    test();
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