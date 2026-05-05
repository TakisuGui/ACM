#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int x,l,r;

int main()
{
    cin>>x>>l>>r;
    int m=1;
    int temple=x;
    
    for(int i=2;i*i<=x;i++)
    {
        if(temple%i==0)
        {
            int cnt=0;
            while(temple%i==0)
            {
                temple/=i;
                cnt++;
            }
            
            if(cnt%2==1) m*=i;
        }
    }
     if(temple>1) m*=temple;
    
    int min_k=ceil(sqrt((double)l/m));
    int max_k=floor(sqrt((double)r/m));
    
    if(min_k<=max_k) cout<<min_k*min_k*m<<endl;
    else cout<<"-1"<<endl;
    
    return 0;
}