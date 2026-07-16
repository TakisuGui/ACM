#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n; cin>>n;
    bool first_dex=true;
    for(int i=n;i>=1;i--)
    {
        if(first_dex)
        {
            cout<<i;
            first_dex=false;
            continue;
        }
        cout<<","<<i;
    }

    return 0;
}