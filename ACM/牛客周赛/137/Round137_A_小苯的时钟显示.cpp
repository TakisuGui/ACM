#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n; cin>>n;
    int h=0,m=0,s=0;
    
    if(n>=3600)
    {
        h=n/3600;
        n-=h*3600;
    }
    if(n>=60)
    {
        m=n/60;
        n-=m*60;
    }
    s=n;

    cout<<h<<" "<<m<<" "<<s<<endl;
    
    return 0;
}