#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e5+10;

int t;
ll a[N];
ll sum[N];
ll n;

int main()
{
    cin>>t;

    while(t--)
    {
        memset(sum,0,sizeof sum);

        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];

        sort(a+1,a+1+n);

        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];


        for(int i=1;i<=n;i++)
        {
            if(i==1) cout<<"0";

            else if(i==2) cout<<" 0";

            else
            {
                bool found = false;
                ll tail=n;
                while(tail-i+1>0)
                {
                    ll d=sum[tail]-sum[tail-i];
                    if(2*a[tail]<d)
                    {
                        cout<<" "<<d;
                        found=true;
                        break;
                    }

                    tail--;
                }

                if(!found)  cout<<" 0";

            }
        }
        cout<<endl;
    }

    return 0;
}