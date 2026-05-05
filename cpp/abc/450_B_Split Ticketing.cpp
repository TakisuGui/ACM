#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n; cin>>n;
    vector<vector<ll>> mp(n,vector<ll>(n,0));

    for(int i=0;i<n-1;i++)
       for(int j=i+1;j<n;j++)
            cin>>mp[i][j];
    
    for(int a=0;a<n-2;a++)
    {
        for(int b=a+1;b<n-1;b++)
        {
            for(int c=b+1;c<n;c++)
            {
                if(mp[a][b]+mp[b][c]<mp[a][c])
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
        
    cout<<"No"<<endl;

    return 0;
}