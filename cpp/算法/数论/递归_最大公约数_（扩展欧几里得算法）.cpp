#include<bits/stdc++.h>
using namespace std;

tuple<int,int,int> extended_gcd(int a,int b)
{
    if(b==0) return {a,1,0};

    int g,x1,y1;
    tie(g,x1,y1)=extended_gcd(b,a%b);

    int x=y1;
    int y=x1-(a/b)*y1;

    return {g,x,y};
}

int main()
{
    int a,b;cin>>a>>b;
    int g,x,y;
    tie(g,x,y)=extended_gcd(a,b);

    cout<<a<<"*"<<x<<"+"<<b<<"*"<<y<<"="<<g<<endl;

    return 0;
}