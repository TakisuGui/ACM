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
        int n;cin>>n;
        vector<int> a(n);
        int max_dex=0;
        int max_sc=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            max_dex=max(max_dex,a[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]==max_dex) max_sc++;
        }
        
        if(max_sc==1)
        {
            for(int i=0;i<n;i++)
            {
                if(a[i]==max_dex) cout<<"1";
                else cout<<"0";
            }
            cout<<"\n";
        }
        else if(max_sc>1&&max_sc<n)
        {
            if(max_sc%2==0)
            {
                for(int i=0;i<n;i++)
                {
                    if(a[i]!=max_dex) cout<<"1";
                    else cout<<"0";
                }
                cout<<"\n";
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    if(a[i]==max_dex) cout<<"1";
                    else cout<<"0";
                }
                cout<<"\n";
            }
        }
        else 
        {
            if(max_sc%2==0)
            {
                for(int i=0;i<n;i++) cout<<"0";
                cout<<"\n";
            }
            else
            {
                for(int i=0;i<n;i++) cout<<"1";
                cout<<"\n";
            }
        }
        
    }
    return 0;
}