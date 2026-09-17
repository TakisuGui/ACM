#include<bits/stdc++.h>
using namespace std;

int n,k;
int sum,ans;

void dfs(int place,int begin)
{
    if(place>k-1)
    {
        if(sum==n)ans++;
        return;
    }

    for(int i=begin;i<=n;i++)
    {
        if(sum+i*(k-place)>n)return;

        sum+=i;

        dfs(place+1,i);

        sum-=i;
    }

}



int main()
{
    cin>>n>>k;

    dfs(0,1);

    cout<<ans<<endl;


    return 0;
}