#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin>>n;
    ll len=1<<n;
    for (ll i=0;i<len;i++)
    {
        int gray= i^(i>>1);
        cout<<gray;
        if (i!=len-1) cout<<" ";
    }
    cout<<endl;
    
    return 0;
}