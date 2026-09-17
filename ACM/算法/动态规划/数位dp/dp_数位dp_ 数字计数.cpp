#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll

int count(int num,int d)
{
    int ans=0;
    // left : 当前位左边的情况数
	// right : 当前位右边的情况数

    for(int right=1,tmp=num,left,cur;tmp!=0;right*=10,tmp/=10)
    {
        left=tmp/10;
        cur=tmp%10;
        if(d==0) left--;

        ans+=left*right;
        if(cur>d) ans+=right;
        else if(cur==d) ans+=num%right+1;
    }

    return ans;
}

int digitsCount(int d,int a,int b)
{
    return count(b,d)-count(a-1,d);
}

void solve()
{
    int a,b; cin>>a>>b;

    for(int i=0;i<=9;i++)
    cout<<digitsCount(i,a,b)<<" ";
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