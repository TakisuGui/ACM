#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=1e9+10;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;cin>>t;


    while(t--)
    {
        ll n,m;cin>>n>>m;
        ll a[n+1],b[m+1];
        
        ll sum_a=0,sum_b=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum_a+=a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>b[i];
            sum_b+=b[i];
        }
        
        if(sum_a==sum_b)
        {
            cout<<"1"<<endl;
            continue;
        }
        
        else if(sum_a>sum_b)
        {
            sort(a+1,a+1+n);
            int num_a=0;
            for(int j=n;j>=1;j--)
            {
                sum_a=sum_a-a[j];
                num_a++;
                if(sum_a<=sum_b) break;
            }
            
            cout<<num_a<<endl;
        }
        
        else if(sum_b>sum_a)
        {
            sort(b+1,b+1+m);
            int num_b=0;
            for(int j=m;j>=1;j--)
            {
                sum_b=sum_b-b[j];
                num_b++;
                if(sum_b<=sum_a) break;
            }
            
            cout<<num_b<<endl;
        }
        
    }
    return 0;
    
}