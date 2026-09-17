#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int h,w,q; cin>>h>>w>>q;

    while(q--)
    {
        int op; cin>>op;
        if(op==1)
        {
            int r; cin>>r;
            cout<<r*w<<endl;
            h-=r;
        }
        else if(op==2)
        {
            int q; cin>>q;
            cout<<q*h<<endl;
            w-=q;
        }
    }

    return 0;
}