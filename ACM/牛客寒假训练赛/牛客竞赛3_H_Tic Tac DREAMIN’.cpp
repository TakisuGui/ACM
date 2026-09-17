#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=1e9+10;


int main()
{   
    ll xa,ya,xb,yb;
    cin>>xa>>ya>>xb>>yb;
    
    ll line=ya*xb-xa*yb;
    ll k=yb-ya;
    
    if(k==0)
    {
        if(abs(line)==4) printf("0.0\n");
        else cout<<"no answer"<<endl;
    }
    
    else
    {
        double x1=(-line+4.0)/k;
        double x2=(-line-4.0)/k;
        
        printf("%.10lf\n",x1);
    }
    
    
    return 0;
    
}