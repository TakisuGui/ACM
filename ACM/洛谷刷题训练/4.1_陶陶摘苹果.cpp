#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int ans=0;
    int a[11];

    for(int i=1;i<=10;i++) cin>>a[i];

    int high;cin>>high;

    for(int i=1;i<=10;i++) if(high+30>=a[i]) ans++;

    cout<<ans<<endl;

    return 0;
}