#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a,b,c,x,y;

int main()
{
    cin>>a>>b>>c>>x>>y;
    
    while(c>=x||b>=y)
    {
        b+=(c/x);
        c-=(c/x)*x;
        
        a+=(b/y);
        c+=(b/y);
        b-=(b/y)*y;
    }
    
    cout<<a<<endl;
    
    return 0;
}