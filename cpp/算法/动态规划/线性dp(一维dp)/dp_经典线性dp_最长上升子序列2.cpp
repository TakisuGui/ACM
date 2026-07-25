#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n;
int a[N];
int dp[N];
int len;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        if(len==0||dp[len]<a[i]) dp[++len]=a[i];
        else
        {
            int l=1,r=len;
            while(l<=r)
            {
                int mid=(l+r)/2;

                if(dp[mid]>=a[i]) r=mid-1;
                else l=mid+1;
            }

            dp[l]=a[i];
        }
    }

    cout<<len<<endl;

    return 0;
}