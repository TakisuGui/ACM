#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a,b;

void slove()
{
    cin>>a>>b;
    int max_dex=max(a,b);

    int l=0,r=5e8;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        ll used=(mid*mid+1)/2;

        if(max_dex<=used&&mid*mid>=a+b) r=mid-1;
        else l=mid+1;
    }

    cout<<l<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        slove();
    }

    return 0;
}