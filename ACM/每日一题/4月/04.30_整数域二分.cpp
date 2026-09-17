#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e5+10;

vector<int> a(N);

void solve()
{
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a.begin()+1,a.begin()+1+n);

    while(q--)
    {
        int mindex,maxdex; cin>>mindex>>maxdex;

        // int l=1,r=n,  left=0,right=n+1; // left 是最后一个 < mindex 的位置                              
        // while(l<=r)                   // right 是第一个  > maxdex 的位置
        // {
        //     int mid=(l+r)/2;

        //     if(a[mid]<mindex)
        //     {
        //         left=mid;
        //         l=mid+1;
        //     }
        //     else r=mid-1;
        // }


        // l=1,r=n;
        // while(l<=r)
        // {
        //     int mid=(l+r)/2;

        //     if(a[mid]>maxdex)
        //     {
        //         right=mid;
        //         r=mid-1;
        //     }
        //     else l=mid+1;
        // }

        // cout<<(right-1-(left+1)+1)<<endl;


        auto left=lower_bound(a.begin()+1,a.begin()+1+n,mindex);
        auto right=upper_bound(a.begin()+1,a.begin()+1+n,maxdex);

        cout<<(right-left)<<endl;
    }
}


int main()
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