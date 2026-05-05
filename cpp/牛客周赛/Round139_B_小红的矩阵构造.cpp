#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,m; cin>>n>>m;

    if(n>=2&&m>=2)
    {
        cout<<"-1"<<endl;
        return 0;
    }

    else if(n==1&&m==1) cout<<"-1"<<endl;
    else if(n==1&&m>1)
    {
        cout<<"0";
        for(int i=2;i<=m;i++) cout<<"1";
        cout<<endl;
    }
    else if(m==1&&n>1)
    {
        cout<<"0"<<endl;
        for(int i=2;i<=n;i++) cout<<"1"<<endl;;
    } 

    return 0;
}


