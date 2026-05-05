#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=10e5+10;
ll n,k;
ll a[N];
ll sum;

int find()
{
    int l=1;int r=sum/k;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        int str=0;

        for(int i=1;i<=n;i++)
        {
            str+=a[i]/mid;
        }
        if(str>=k)l=mid;
        else r=mid-1;
    }

    return l;

}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    if(k>sum)
    {
        cout<<"0";
        return 0;
    }

    int ans=find();

    cout<<ans<<endl;


    return 0;
}