#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+10;
int a[N];
int tmp[N];

int n;

ll part_sort(int l,int r)
{
    if(l>=r) return 0;

    ll ans=0;
    int mid=(l+r)/2;
    ans+=part_sort(l,mid);
    ans+=part_sort(mid+1,r);

    int cur1=l,cur2=mid+1,pass=l;

    while(cur1<=mid&&cur2<=r)
    {
        if(a[cur1]<=a[cur2])
        {
            tmp[pass]=a[cur1];
            pass++; cur1++;
        }
        else 
        {
            ans+=mid-cur1+1;
            tmp[pass]=a[cur2];
            pass++; cur2++;
        }
    }

    while(cur1<=mid) tmp[pass++]=a[cur1++];
    while(cur2<=r)   tmp[pass++]=a[cur2++];

    for(int i=l;i<=r;i++) a[i]=tmp[i];

    return ans;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    cout<<part_sort(1,n)<<endl;

    return 0;
}