#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e9+7;

int n,k;
vector<int> a(N);
vector<int> righ(N);
vector<int> ends_(N);


int bs1(int len,int num)
{
    int l=0,r=len-1,ans=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;

        if(ends_[mid]<num)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }

    return ans;
}

int bs2(int len,int num)
{
    int l=0,r=len-1,ans=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;

        if(ends_[mid]>num)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }

    return ans;
}

void right_()
{
    int len=0;
    for(int i=n-1,find_;i>=0;i--)
    {
        find_=bs1(len,a[i]);
        if(find_==-1)
        {
            ends_[len++]=a[i];
            righ[i]=len;
        }
        else
        {
            ends_[find_]=a[i];
            righ[i]=find_+1;
        }
    }
}


void solve()
{
    cin>>n>>k;
    if (k>=n) { cout<<n<<endl; return;}
    for(int i=0;i<n;i++) cin>>a[i];
    right_();

    int len=0,ans=0;
    for(int i=0,j=k,find,left;j<n;i++,j++)
    {
        find=bs2(len,a[j]);
        left= find==-1 ? len : find;
        ans=max(ans,left+k+righ[j]);

        find=bs2(len,a[i]);
        if(find==-1) ends_[len++]=a[i];
        else ends_[find]=a[i];
    }

    ans=max(ans,len+k);
    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}
