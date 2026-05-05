#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;

int n;
int a[N];
int temp,ans=-1e9;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        temp+=a[i];
        ans=max(ans,temp);
        
        if(temp<0)
        {
            temp=0;
        }
    }
    
    cout<<ans<<endl;

    return 0;
}