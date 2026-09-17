#include<bits/stdc++.h>
using namespace std;

const int N=20;

int main()
{
    int x;cin>>x;
    
    bool find_x=false;
    for(int i=1;i<=10;i++)
    {
        if(x==i*(i-1)) 
        {
            find_x=true;
            break;
        }
    }
    
    if(find_x) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}