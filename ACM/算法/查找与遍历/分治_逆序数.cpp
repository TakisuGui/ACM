#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5e5+10;
ll a[N];
int temp[N];
ll n;


ll dfs(ll a[],ll l,ll r)
{
    if(l>=r)return 0;
    
    ll sum=0;

    ll mid=(l+r)/2;

    sum+=dfs(a,l,mid);
    sum+=dfs(a,mid+1,r);

    
   ll left=l,right=mid+1,i=l;

   while(left<=mid&&right<=r)
   {
      if(a[left]<=a[right])temp[i++]=a[left++];
      else
      {
        sum+=mid-left+1;
        temp[i++]=a[right++];
      }
   }

   while(left<=mid)temp[i++]=a[left++];
   while(right<=r)temp[i++]=a[right++];

   for(int j=l;j<=r;j++)a[j]=temp[j];

   return sum;

}

int main()
{
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];

    ll ans=dfs(a,1,n);

    cout<<ans<<endl;

    return 0;
}


