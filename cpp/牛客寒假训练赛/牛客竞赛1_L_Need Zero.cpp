#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int x;cin>>x;
    for(int i=1;i<=10;i++)
    {
        if((i*x)%10==0)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    
}