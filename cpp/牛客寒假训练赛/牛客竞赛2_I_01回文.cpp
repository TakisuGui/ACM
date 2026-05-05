#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        vector<string> a(n);
        int dex_0=0,dex_1=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            for(char c:a[i])
            {
                if(c=='0') dex_0++;
                else dex_1++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='0'&&dex_0>1) cout<<"Y";
                else if(a[i][j]=='1'&&dex_1>1) cout<<"Y";
                else cout<<"N";
            }
            cout<<'\n';
        }
    }
    return 0;
}