#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;
int t;
ll a[N];
ll n,k;
int f[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        ll sum=0,rem_sum=0;

        cin>>n>>k;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];

            f[i]=a[i]%k;
            rem_sum+=f[i];
        }

        sort(f+1,f+n+1);
        ll left=1,right=n;
        ll save=0;
        while(left<right)
        {
            if(f[left]+f[right]>=k)
            {
                save+=k;
                left++;
                right--;              
            }
            else left++;
        }

        ll loss=rem_sum-save;
        cout<<(sum-loss)/k<<endl;
    }

    return 0;
}