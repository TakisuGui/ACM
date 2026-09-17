#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n; cin>>n;
    if(n==1)
    {
        cout<<"1"<<endl;
        return 0;
    }

    ll ans=0;
    int i=2;

    while(n!=1)
    {
        if(n%i!=0)
        {
            i++;
            continue;
        }

        n/=i;
        ans+=i;
    }

    cout<<ans<<endl;

    return 0;
}