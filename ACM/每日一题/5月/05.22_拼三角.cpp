#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

bool isTriangle(ll a,ll b,ll c) 
{
    return (a+b>c) && (a+c>b) && (b+c>a);
}

void solve()
{
    vector<ll> s(6);
    for(int i=0;i<6;++i) cin>>s[i];

    for(int i=0;i<6;i++)
    {
        for(int j=i+1;j<6;j++)
        {
            for(int k=j+1;k<6;k++)
            {
                int a=s[i],b=s[j],c=s[k];

                vector<int> others;
                for(int m=0;m<6;m++)
                {
                    if(m!=i&&m!=j&&m!=k) others.push_back(s[m]);
                }

                int x=others[0],y=others[1],z=others[2];

                if(isTriangle(a,b,c) && isTriangle(x,y,z))
                {
                    cout<<"Yes"<<endl;
                    return;
                }
            }
        }
    }

    cout<<"No"<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}