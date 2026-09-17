#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin>>k;

    for(int m=k+1;;m++)
    {
        int pos=0;
        bool ok=true;
        int remain=2*k;

        for(int i=1;i<=k;i++)
        {
            pos=(pos+m-1)%remain;

            if(pos<k)
            {
                ok=false;
                break;
            }
            else remain--;
        }

        if(ok)
        {
            cout<<m<<endl;
            return 0;
        }
    }
}