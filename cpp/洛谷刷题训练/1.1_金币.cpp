#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int k;

int main()
{
    cin>>k;
    ll sum=0;
    ll day=0;

    int t=1;
    while(1)
    {
        if(day>=k) break;

        for(int i=1;i<=t;i++)
        {
            if(day>=k) break;
            sum+=t;
            day++;
        }

        t++;
    }

    cout<<sum<<endl;

    return 0;
}