#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6+10;

int m,n;

void solve()
{
    int h,w; cin>>h>>w;

    if(h==1||w==1)
    {
        if(h==1&&w==1) 
        {
            cout<<"0";
        }
        else if(h==1)
        {
            for(int i=1;i<=w;i++)
            {
                if(i==1) cout<<"1";
                else if(i==w) cout<<" 1";
                else cout<<" 2";
            }
        }
        else
        {
            for(int i=1;i<=h;i++)
            {
                if(i==1||i==h) cout<<"1"<<endl;
                else cout<<"2"<<endl;
            }
        }

        return;
    }

    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if((j==1||j==w)&&(i==1||i==h))
            {
                if(j==1) cout<<"2";
                else cout<<" 2";
            }
            else if(((i==1||i==h)&&(j>=2&&j<=w-1))||((j==1||j==w)&&(i>=2&&i<=h-1)))
            {
                if(j==1) cout<<"3";
                else cout<<" 3";
            }
            else cout<<" 4";
        }
        cout<<endl;
    }
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