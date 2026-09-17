#include<bits/stdc++.h>
using namespace std;

const int N=1e5-10,p=131;
typedef unsigned long long ULL;

int n;
ULL a[N];

ULL get_hash(string& s)
{
    ULL ret=0;
    for(auto c:s)
    {
        ret=ret*p+c;
    }

    return ret;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;

        a[i]=get_hash(s);
    }

    sort(a+1,a+1+n);
    ULL ans=0;

    for(int i=1;i<=n;i++) if(a[i]!=a[i-1])ans++;


    cout<<ans<<endl;
    
    return 0;
}