#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<bool> vistit(n+1,false);
    vector<int> prime(n/2+1);

    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(!vistit[i]) prime[cnt++]=i;

        for(int j=0;j<cnt;j++)
        {
            if(i*prime[j]>n) break;

            vistit[i*prime[j]]=true;
            if(i%prime[j]==0) break;
        }
    }

    for(int i=0;i<cnt;i++) cout<<prime[i]<<endl;

    return 0;
}