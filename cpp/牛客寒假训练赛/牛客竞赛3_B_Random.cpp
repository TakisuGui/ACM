#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    else return a=gcd(b,a%b);
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;cin>>t;
    while(t--)
    {    
        ll n;cin>>n;
        bool find_pass=false;
        ll a[n+1]; for(int i=1;i<=n;i++) cin>>a[i];
        
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(gcd(a[i],a[j])>1)
                {
                    cout<<a[i]<<" "<<a[j]<<endl;
                    find_pass=true;
                    break;
                }
            }
            if(find_pass) break;
        }
        
        if(!find_pass) cout<<"-1"<<endl;

    }

    return 0;
}