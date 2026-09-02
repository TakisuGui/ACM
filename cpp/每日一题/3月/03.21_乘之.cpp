#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,k; cin>>n>>k;
        ll sum=0;
        for(int i=1;i<=n;i++)
        {
            int x; cin>>x;
            sum+=x;
        }
        sum*=k;
        cout<<sum<<endl;
    }

    return 0;
}