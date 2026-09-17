#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main()
{
    cin>>n;
    vector<int>a(32,0);

    if(n%2==1)
    {
        cout<<"-1"<<endl;
        return 0;
    }

    int i=0;

    while(n>0)
    {
        a[i]=(n&1);
        i++;
        n>>=1;
    }

    bool first=true;

    for(int j=i-1;j>=0;j--)
    {
        if(first)
        {
            if(a[j]==1) cout<<(1ll<<j);
            first=false;
        }
        else if(a[j]==1) cout<<" "<<(1ll<<j);
    }

    cout<<endl;

    return 0;
}